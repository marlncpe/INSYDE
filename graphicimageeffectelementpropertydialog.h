#ifndef GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H
#define GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#else
#include <QtGui>
#endif

#include "INSYDEUI_global.h"
#include "effect.h"
#include "blackwhiteeffect.h"
#include "graphicimageeffectelement.h"
#include "grayscaleeffect.h"
#include "bnsubwidget.h"
#include "gssubwidget.h"

namespace Ui {
class GraphicImageEffectElementPropertyDialog;
}

class GraphicImageEffectElement;

class INSYDEUISHARED_EXPORT GraphicImageEffectElementPropertyDialog : public QDialog
{
		Q_OBJECT
		
	public:
		explicit GraphicImageEffectElementPropertyDialog(GraphicImageEffectElement *giee, QWidget *parent = 0);
		~GraphicImageEffectElementPropertyDialog();
		
		QVector<Effect*> getEffectList();

		void setGraphicImageEffectElement(GraphicImageEffectElement *giee);
		GraphicImageEffectElement* setGraphicImageEffectElement();

		void setBNEffectChecked(bool chk);
		bool getBNEffectChecked();

		QWidget *getSubWidget();

	private slots:
		void on_lwEffects_currentRowChanged(int currentRow);

	private:
		Ui::GraphicImageEffectElementPropertyDialog *ui;

		GSSubWidget *gssw;
		BNSubWidget *bnsw;
		GraphicImageEffectElement *giee;

		void initGIEEPD(GraphicImageEffectElement *giee);

		void updateConfigWidget(int i);
};

#endif // GRAPHICIMAGEEFFECTELEMENTPROPERTYDIALOG_H
