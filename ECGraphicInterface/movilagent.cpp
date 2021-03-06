#include "movilagent.h"

MovilAgent::MovilAgent()
{
    iniciarAgenteMovil(50, 100);
}

MovilAgent::MovilAgent(double rapidez, double alcance)
{
    iniciarAgenteMovil(rapidez, alcance);
}

void MovilAgent::iniciarAgenteMovil(double rapidez, double alcance)
{
    visionSensor = new VisionSensor(this, alcance, 360);
    addSensor("vision", visionSensor);

    movingActuator = new MovingActuator(this, rapidez, 0, 2);
//    connect(actuadorMovimiento, SIGNAL(llegoADestinoFinal(QPointF)), SLOT(lastCheckPointReached(QPointF)));
    addActuator("movement", movingActuator);

    setVisibleVisionSensorArea(false);

    setVisibleJourney(true);
    setSpeed(rapidez);
    setVisualRange(alcance);
    setDirection(0);

    forma.addEllipse(QRectF(-10, -10, 20, 20));
    setShape(forma);
}

void MovilAgent::setVisualRange(double range)
{
    VisionSensor *sd = (VisionSensor*)getSensor("vision");
    sd->setVisionRange(range);
}

void MovilAgent::setSpeed(double rapidez)
{
    movingActuator->setRapidez(rapidez);
}

double MovilAgent::getSpeed()
{
    return movingActuator->getRapidez();
}

void MovilAgent::addPoint(double x, double y)
{
    movingActuator->addPoint(x, y);
}

void MovilAgent::addPoint(const QPointF &pt)
{
    movingActuator->addPoint(pt);
}

void MovilAgent::clearPoints()
{
    movingActuator->clearPoints();
}

QRegion MovilAgent::getRegion(){ //Arreglar
    QPainterPath path;
    if(getVisibleJourney()){
        path.addPath(mapFromScene(movingActuator->getTrayectoria()));
    }
    if(getVisibleVisionSensorArea()){
        path.addPath(mapFromScene(visionSensor->getCoverArea()));
    }
    path.addPath(forma);
//    path.addPath(mapFromScene(actuadorMovimiento->nextCamino));
//    path.addPath(radialShape());

    return QRegion(path.toFillPolygon().toPolygon());
}

QRectF MovilAgent::boundingRect() const
{
    QPainterPath path;
    if(getVisibleJourney() && includeJourney){
        path.addPath(mapFromScene(movingActuator->getTrayectoria()));
    }
    if(getVisibleVisionSensorArea()){
        path.addPath(mapFromScene(visionSensor->getCoverArea()));
    }
    path.addPath(forma);
    path.addRect(Agent::boundingRect());
//    path.addPath(mapFromScene(actuadorMovimiento->nextCamino));
//    path.addPath(radialShape());
    double medioBorde = getBorderWidth()/2;
    return path.controlPointRect().adjusted(-medioBorde, -medioBorde, medioBorde, medioBorde);
}

void MovilAgent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setClipRect(option->exposedRect);
    Agent::paint(painter, option, widget);
//    QRegion r = getRegion();
////    QPainterPath p;
////    p.addRegion(r);
//    painter->setClipRegion(r);
//    painter->drawPath(p);
    painter->save();
    QPen pen(Qt::black, getBorderWidth());
    Vector2D vec(10, float(theta));
    painter->setPen(pen);
    painter->drawLine(QPointF(0, 0), vec.toPointF());
    if(getVisibleJourney() && (option->state & QStyle::State_Selected)){
        painter->setPen(Qt::gray);
        painter->drawPath(mapFromScene(movingActuator->getTrayectoria()));
        includeJourney = true;
    }else{
        includeJourney = false;
    }

    if(getVisibleVisionSensorArea()){
        painter->setOpacity(0.2);
        painter->setBrush(Qt::yellow);
        painter->setPen(Qt::NoPen);
        painter->drawPath(mapFromScene(visionSensor->getCoverArea()));
    }
//    painter->drawPath(radialShape());
//    painter->setOpacity(0.5);
//    painter->drawPath(mapFromScene(actuadorMovimiento->nextCamino));
//    painter->drawRect(boundingRect());
//    painter->rotate(-1);
//    painter->drawText(0, 25, QString::number(sensorDistancia->getDistanciaPromedio()));
    painter->restore();
}

double MovilAgent::getRadius()
{
    return Vector2D(forma.controlPointRect().center(), forma.controlPointRect().topLeft()).getModulo();
}

void MovilAgent::setDirection(double dir)
{
    theta = M_PI*dir/180;
    setRotation(-theta);
}

double MovilAgent::getDirection()
{
    return (theta*180)/M_PI;
}

void MovilAgent::setDirectionRads(double dir)
{
    theta = dir;
//    setRotation(-theta*180/M_PI);
}

double MovilAgent::getDirectionRads()
{
    return theta;
}

void MovilAgent::stop()
{
    if(movingActuator != NULL)
        movingActuator->stop();
}

void MovilAgent::run()
{
    movingActuator->run();
}

void MovilAgent::moverA(double x, double y)
{
    movingActuator->moverA(x, y);
}

void MovilAgent::moverA(QPointF pt)
{
    movingActuator->moverA(pt);
}

void MovilAgent::moverA(QQueue<QPointF> posiciones)
{
    movingActuator->moverA(posiciones);
}

bool MovilAgent::isMoving()
{
    return movingActuator->isMoving();
}

//void MovilAgent::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    Agent::mousePressEvent(event);
//    prepareGeometryChange();
//}

//void MovilAgent::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    Agent::mouseReleaseEvent(event);
//    prepareGeometryChange();
//}
