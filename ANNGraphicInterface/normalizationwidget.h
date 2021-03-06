#ifndef NORMALIZATIONWIDGET_H
#define NORMALIZATIONWIDGET_H

#include <QWidget>

#include "../labeledspinboxwidget.h"
#include "../minmaxvaluewidget.h"
#include "ANNFramework/trainingsetinterface.h"

namespace Ui {
	class NormalizationWidget;
}

class NormalizationWidget : public QWidget
{

	public:

		explicit NormalizationWidget(const QString &title = "Normalization", QWidget *parent = 0);
		~NormalizationWidget();

		void setMinValue(double val);
		double getMinValue() const;

		void setMinValueMaximum(double val);
		double getMinValueMaximum() const;

		void setMinValueMinimum(double val);
		double getMinValueMinimum() const;

		void setMaxValue(double val);
		double getMaxValue() const;

		void setMaxValueMaximum(double val);
		double getMaxValueMaximum() const;

		void setMaxValueMinimum(double val);
		double getMaxValueMinimum() const;

		void setThresholdValue(double val);
		double getThresholdValue() const;

		void setThresholdValueMaximum(double val);
		double getThresholdValueMaximum() const;

		void setThresholdValueMinimum(double val);
		double getThresholdValueMinimum() const;

		void setAmplitudeValue(double amp);
		double getAmplitudeValue() const;

		void setElongationValue(double elong);
		double getElongationValue() const;

		void setCurrentNormalization(ITrainingSet::NormalizationType nt);
		ITrainingSet::NormalizationType getCurrentNormalization() const;

	signals:

		void normalizationChanged(Normalization);
		void normalizationChanged(ITrainingSet::NormalizationType nt);
		void amplitudeValueChanged(double val);
		void elongationValueChanged(double val);
		void thresholdValueChanged(double val);
		void minValueChanged(double val);
		void maxValueChanged(double val);

	private slots:
		void on_cbNormalizationType_currentIndexChanged(int index);

		void onAmplitudeValueChanged(double val);
		void onElongationValueChanged(double val);
		void onThresholdChanged(double val);
		void onMinValueChanged(double val);
		void onMaxValueChanged(double val);

	private:

		Q_OBJECT

		LabeledDoubleSpinBoxWidget *lsbwAmplitude;
		LabeledDoubleSpinBoxWidget *lsbwElongation;
		LabeledDoubleSpinBoxWidget *lsbwThreshold;
		DoubleMinMaxValueWidget *mmvw;
		Ui::NormalizationWidget *ui;

		void initNW(const QString &title);
};

#endif // NORMALIZATIONWIDGET_H
