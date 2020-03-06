#include "blackBullet.hpp"
#include "DirtyEffect.hpp"

blackBullet::blackBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
Bullet("play/bullet6.png", 600, 15, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    
}
void blackBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-3.png", dist(rng), enemy->Position.x, enemy->Position.y));
}

