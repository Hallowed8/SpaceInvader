#include "game.h"

Game::Game(GameGui *gameGui, int width, int height, int updateFrequency)
{
    this->width = width;
    this->height = height;
    this->updateFrequency = updateFrequency;
    this->gameGui = gameGui;

    Object* player = new Fighter(200, QPoint(500,500), QPoint(100,100), 6);
    this->objects.append(player);

    gameGui->startGameGui(objects);

    gameLoopTimer = new QTimer();
    gameLoopTimer->start(15);
    connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(updateState()));
}
//-----------------------
//some non-member functions declarations

QPoint spawnCoor(int x_min, int x_max);
bool doCollide(Object* obj_1, Object* obj_2);

//-----------------------
void Game::updateState()
{

    collisionHandler();
    spawnEnemy();
    updateObjects();
    updatePos();
    gameGui->update(objects);
    gameGui->score->setScore(score);
}

void Game::collisionHandler()
{
    // this loop iterates through objects vector and checks if any is out of the game window
    QVector<GraphicObject*>::iterator g_it;
    g_it = gameGui->graphicObjects.begin();
    QVector<Object*>::iterator it;
    for(it = objects.begin(); it<objects.end(); ){
        if((*it)->getPos().x() > width+(*it)->getSize().x() || (*it)->getPos().x() < -(*it)->getSize().x()){
            delete *it;
            objects.erase(it);
            delete *g_it;
            gameGui->graphicObjects.erase(g_it);
        }
        else if((*it)->getPos().y() > height+(*it)->getSize().y() || (*it)->getPos().y() < -(*it)->getSize().y()){
            delete *it;
            objects.erase(it);
            delete *g_it;
            gameGui->graphicObjects.erase(g_it);
        }
        else {
            ++it;
            ++g_it;
        }
    }
    objectCollision();
}

void Game::objectCollision()
{
    QVector<Object*>::iterator first_it;
    QVector<Object*>::iterator second_it;

    QVector<GraphicObject*>::iterator first_git = gameGui->graphicObjects.begin();
    QVector<GraphicObject*>::iterator second_git;

    for(first_it = objects.begin(); first_it < objects.end()-1; ){
        second_it = first_it+1;
        second_git = first_git+1;
        for (second_it ; second_it<objects.end(); ){
            if(doCollide(*first_it, *second_it)){
                if(Bullet* fig = dynamic_cast<Bullet*>(*first_it)) {
                    if(Bullet* bul = dynamic_cast<Bullet*>(*second_it))
                        break;
                }else if(Fighter* fig = dynamic_cast<Fighter*>(*first_it)) {
                    if(Bullet* bul = dynamic_cast<Bullet*>(*second_it))
                        break;
                }else if(Enemy* fig = dynamic_cast<Enemy*>(*first_it)) {
                    if(Bullet* bul = dynamic_cast<Bullet*>(*second_it)){
                        ++score;
                    }
                    if(EnemyBullet* bul = dynamic_cast<EnemyBullet*>(*second_it))
                        break;
                }
                else if(Cruiser* cru = dynamic_cast<Cruiser*>(*first_it)) {
                    if(Bullet* bul = dynamic_cast<Bullet*>(*second_it))
                        break;
                }
                int front_hp = (*first_it)->getHp();
                (*first_it)->changeHp(-(*second_it)->getHp());
                (*second_it)->changeHp(-front_hp);
                if((*first_it)->getHp()<=0){
                    delete *first_it;
                    objects.erase(first_it);
                    second_it = first_it +1;
                    delete *first_git;
                    gameGui->graphicObjects.erase(first_git);
                    break;
                }
                if((*second_it)->getHp()<=0){
                    delete *second_it;
                    objects.erase(second_it);
                    delete *second_git;
                    gameGui->graphicObjects.erase(second_git);
                    --second_it;
                    --second_git;
                }
            }
            ++second_it;
            ++second_git;
        }
        ++first_it;
        ++first_git;
    }
}

void Game::updateObjects(){
    for(auto obj: objects){
        if(!obj->newObjects.isEmpty()){
            objects.append(obj->newObjects);
            obj->newObjects.clear();
        }
    }
}

void Game::updatePos()
{
    for(int i = 0; i<objects.size(); ++i){
        objects[i]->update();
    }
}

QPoint spawnCoor(int x_min, int x_max);


void Game::spawnEnemy()
{
    if(spawnIterator>spawnPeriod){
        spawnIterator = 0;
        Object* enemy = new Enemy(40,spawnCoor(20,980),QPoint(50,70),2,30);
        objects.append(enemy);
    }
    ++spawnIterator;
}
QPoint spawnCoor(int x_min, int x_max){
    int x = rand() %x_max+x_min;
    int y = -50;
    return QPoint(x,y);
}
bool doCollide(Object* obj_1, Object* obj_2){
    // auxilary variables denoting rectangles edges
    int right_edge_1 = obj_1->getPos().x()+obj_1->getSize().x();
    int left_edge_1 = obj_1->getPos().x();
    int upper_edge_1 = obj_1->getPos().y();
    int lower_edge_1 = obj_1->getPos().y()+obj_1->getSize().y();

    int right_edge_2 = obj_2->getPos().x()+obj_2->getSize().x();
    int left_edge_2 = obj_2->getPos().x();
    int upper_edge_2 = obj_2->getPos().y();
    int lower_edge_2 = obj_2->getPos().y()+obj_2->getSize().y();

    if(right_edge_1 < left_edge_2 || left_edge_1 > right_edge_2){
        return false;
    }
    if(upper_edge_1 > lower_edge_2 || lower_edge_1 < upper_edge_2){
        return false;
    }
    return true;
}














