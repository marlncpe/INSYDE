#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QMenu>
#include <QStyleOptionGraphicsItem>

#include <QPen>
#include <QPainter>

#include "INSYDEUI_global.h"

/**
  @class GraphicElement esta clase es la base para todos los objetos que necesitan ser representado en un sistema.
  */
class INSYDEUISHARED_EXPORT GraphicElement : public QGraphicsObject
{
	public:

		/**
		 *Tipo de elemento grafico
		 */
		enum {GraphicElementType = UserType + 1};

		/**
		  Construye un objeto GraphicElement con un tama�o de 50x50 pixeles y un borde de dos pixeles
		  */
		explicit GraphicElement();

		/**
		  Construye un objeto con las dimensiones especificadas por @code{rect}

		  @param const QRectF &rect - Rectangulo que contiene las dimensiones del objeto grafico
		  @param int borde - Ancho del borde
		  */
		explicit GraphicElement(const QRectF &rect, int border = 2);

		/**
		  Destructor de la clase
		  */
		~GraphicElement();

		/**
		  Configura un menu contextual a partir del parametro @class{menu}, esta funcion debe ser llamada
		  desde el visor cuando se hace click sobre este con el boton secundario.

		  @param QMenu *menu - Puntero al menu creado cuando se hace click con el secundario. @class{menu} es null
							   el comportamiento es impredecible
		  */
		virtual QMenu* getContextMenu(QMenu *menu);

		/**
		  Establece el ancho del borde de los graficos

		  @param int width - Ancho del borde
		  */
		void setBorderWidth(int width);

		/**
		  Establece la dimension del objeto grafico

		  @param const QRectF &rect - Rectangulo con la dimension del objeto grafico
		  */
		virtual void setRectangle(const QRectF &rect);
		virtual void setRectangle(const QRect &rect);

		/**
		  Devuelve la dimension del objeto grafico

		  @return QRectF Rectangulo que contiene la dimension del objeto grafico
		  */
		virtual QRectF getRectangle() const;

		/**
		  Asigna el elemento que proporcionara el valor de entrada para este objeto
		  grafico. Esta funcion es virtual pura ya que depende del comportamiento de
		  cada uno de los objetos que hereden de esta clase base

		  @param GraphicElement *ge - Puntero al elemento que se le asignara
		  */
		virtual void setInputElement(GraphicElement *ge) = 0;

		/**
		 * @brief getInputElement Obtiene el elemento que proporciona el valor de entrada.
		 * @return
		 */
		virtual GraphicElement* getInputElement() const;

		/**
		 * @brief setOutputElement Conecta este elemento grafico con un elemento al cual se le asignara la salida de este.
		 * @param ge Elemento grafico al cual sera conectado
		 */
		virtual void setOutputElement(GraphicElement *ge);

		/**
		 * @brief getOutputElement Obtiene el elemento al cual esta conectado.
		 * @return
		 */
		virtual GraphicElement* getOutputElement() const;

		/**
		  Vease funcion @code{type()} de la clase @code{QGraphicsItem}

		  @see type
		  */
		int type() const;

	protected:

		//Elemento de entrada
		GraphicElement *inputElement;

		//Elemento de salida
		GraphicElement *outputElement;

		//Funciones heredadas
		QPainterPath shape() const;
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

		//        void mousePressEvent(QGraphicsSceneMouseEvent *event);
		//        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
		//        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

	protected slots:
		/**
		  Esta funcion es llamada cuando se hace click en el elemento "Propiedades" del menu contextual
		  */
		virtual void onPropertyClick() = 0;

		/**
		  Esta funcion es llamada cuando se hace click en el elemento "Eliminar" del menu contextual
		  */
		virtual void onDeleteClick();

		/**
		 * @brief onOpenClick Es llamado cuando se hace click en el elemento abrir del menu contextual
		 */
		virtual void onOpenClick() = 0;

	private:

		Q_OBJECT

		//Ancho de borde del objeto
		int border;

		//Ancho del marco
		int sep;

		//Rectangulo que contiene las dimensiones de este objeto grafico
		QRectF rectangle;

		//Rectangulo interno
		QRectF intRectangle;

		/**
		  Inicializa el objeto constructor con una dimension @code{rect} y un ancho de borde @code{border}

		  @param const QRectF &rect - Rectangulo que contiene las dimensiones del objeto grafico
		  @param int border - Ancho del borde de este objeto grafico
		  */
		void initGE(const QRectF &rect, int border);
};

#endif // GRAPHICELEMENT_H
