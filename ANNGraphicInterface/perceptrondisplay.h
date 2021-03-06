#ifndef PERCEPTRONDISPLAY_H
#define PERCEPTRONDISPLAY_H

#include <QInputDialog>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QPainter>
#include <QDoubleValidator>

#include <algorithm>
#include <float.h>

#include "weightline.h"
#include "ANNFramework/simpleperceptron.h"

using namespace std;

class WeightEditProxy;
class Soma;

class PerceptronDisplay : public QGraphicsScene
{

	public:
		explicit PerceptronDisplay(SimplePerceptron *sp);

		~PerceptronDisplay();

		void setInputSize(int n);
		int getInputSize();

		void setWeightsVector(vector<double> weights);
		vector<double> getWeightsVector() const;

		void setPerceptron(SimplePerceptron *sp);
		SimplePerceptron* getPerceptron();

	signals:

	public slots:

		void onWeightValueChanged(int index, double before, double after);

	private:

		Q_OBJECT
		SimplePerceptron *sp;
		QVector<WeightLine*> gliWeights;
		QVector<QGraphicsEllipseItem*> geiInputs;
		Soma *nucleo;

		void initPDisplay(SimplePerceptron *sp);

		void updateWeightLines(vector<double> weights);
};

class WeightEditProxy : public QGraphicsProxyWidget
{

	public:

		enum NodePosition{
			Left,
			Right,
			Top,
			Bottom
		};

		QLineEdit *leValue;

		explicit WeightEditProxy(QGraphicsItem *parent = 0);

		void setNodePosition(NodePosition nodePosition);
		NodePosition getNodePosition();

		QPointF getNodeCenter() const;

	protected:
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	private:
		Q_OBJECT

		NodePosition nodePosition;
		QWidget *wg;
		int nodeDiameter;
		QRectF nodeRect;

		void initWE();
};

class Soma : public QGraphicsEllipseItem
{
	public:
		explicit Soma(QGraphicsItem * parent = 0, QGraphicsScene *scene = 0);
		explicit Soma(const QRectF & rect, QGraphicsItem * parent = 0, QGraphicsScene *scene = 0);
		explicit Soma(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0, QGraphicsScene *scene = 0);

		/**
		 * @brief getCenter devuelve el centro del nucleo del perceptron (graficamente hablando). Esta funcion puede ser reemplazada por
		 * @code{QRectF::center()}
		 * @return Punto en el cual se encuentra el centro del nucleo.
		 *
		 * TODO: se debe reemplazar por QRectF::center() o buscar una reimplementacion
		 */
		QPointF getCenter() const;

		QRectF boundingRect() const;

	protected:
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PERCEPTRONDISPLAY_H
