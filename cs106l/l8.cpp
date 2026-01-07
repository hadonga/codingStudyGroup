#include "l8.hpp"
#include <cmath>  // for sqrt
#include <vector>
#include <memory>  // for std::unique_ptr

// 定义HitBox类（简单AABB碰撞盒）
class HitBox {
public:
    double width, height, depth;  // 碰撞盒尺寸
    HitBox(double w, double h, double d) : width(w), height(h), depth(d) {}
    bool overlaps(const HitBox& other) const {
        // 简单AABB重叠检查（假设中心对齐）
        return (width/2 + other.width/2 > 0) &&  // 简化，实际需要位置
               (height/2 + other.height/2 > 0) &&
               (depth/2 + other.depth/2 > 0);
    }
};

Point::Point(int x, int y){
  _x = x;
  _y = y;
}

int Point::getX(){
  return _x;
}

int Point::getY(){
  return _y;
}

void Point::setX(int x){
  _x = x;
}

void Point::setY(int y){
  _y = y;
}

Point p1(3, 4);

void setPoint(Point pt){
  pt.setX(10);
  pt.setY(20);
  std::cout<< pt.getX() << pt.getY() << '\n';
}
// common base class example

class Entity {
protected:
  double x,y,z;
  HitBox hb;
public:
  Entity(double px = 0, double py = 0, double pz = 0, HitBox h = HitBox(1,1,1))
      : x(px), y(py), z(pz), hb(h) {}
  virtual void update() { std::cout << "Entity updating..." << std::endl; }
  void render();
  virtual double getHitpoints() const { return 0; }  // 虚函数，返回0表示无生命值
  bool overlapsWith(const Entity& other) const {
    // 简化：只检查距离（忽略hitbox复杂检查）
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    return distance < 1.0;  // 距离小于1.0算重叠
  }
};

// ... Player类 ...

class Player: public Entity {
  double hitpoints;
public:
  Player(double px = 0, double py = 0, double pz = 0, HitBox h = HitBox(1,1,1))
      : Entity(px, py, pz, h), hitpoints(100) {}  // 默认生命值100
  double getHitpoints() const override { return hitpoints; }  // 覆盖，返回实际生命值
  void damage(double hp);
};

// ... 其他类 ...

class Projectile : public Entity {
  double vx, vy, vz;  // 速度成员
public:
  Projectile(double px = 0, double py = 0, double pz = 0, HitBox h = HitBox(1,1,1), double vvx = 0, double vvy = 0, double vvz = 0)
      : Entity(px, py, pz, h), vx(vvx), vy(vvy), vz(vvz) {}
  double getVx() const { return vx; }
  double getVy() const { return vy; }
  double getVz() const { return vz; }
};

int main(){
    // 明显的切片例子：Projectile 有速度成员
    Projectile bullet(0, 0, 0, HitBox(1, 1, 1), 10, 20, 30);  // 位置(0,0,0)，速度(10,20,30)
    
    std::cout << "Projectile vx: " << bullet.getVx() << ", vy: " << bullet.getVy() << ", vz: " << bullet.getVz() << std::endl;
    
    // 赋值给基类，发生切片！速度成员丢失
    Entity e = bullet;
    // e.getVx() 不存在，因为切片后只剩基类成员

    // std::cout << "After slicing to Entity:" << e.getVx() <<std::endl;

    std::cout << "Entity (sliced) has no vx/vy/vz - slicing occurred!" << std::endl;
    
    // 向量中的切片
    std::vector<Entity> entities{Player(), Projectile(0,0,0, HitBox(1,1,1), 5,5,5)};
    for (auto& ent : entities) {
        // 无法访问vx/vy/vz，因为向量中都是Entity，切片了
        std::cout << "Entity in vector has no velocity data." << std::endl;
    }
        // 解决切片：使用指针向量，避免切片，实现多态
    std::vector<std::unique_ptr<Entity>> entitiesPtr;
    entitiesPtr.push_back(std::make_unique<Player>());
    entitiesPtr.push_back(std::make_unique<Projectile>(0,0,0, HitBox(1,1,1), 5,5,5));
    
    std::cout << "\nUsing pointers (no slicing):" << std::endl;
    for (auto& ent : entitiesPtr) {
        ent->update();  // 多态调用子类update()
        // 如果需要访问子类特有成员，使用dynamic_cast
        if (auto* proj = dynamic_cast<Projectile*>(ent.get())) {
            std::cout << "Projectile vx: " << proj->getVx() << ", vy: " << proj->getVy() << ", vz: " << proj->getVz() << std::endl;
        }
    }
        return 0;
}