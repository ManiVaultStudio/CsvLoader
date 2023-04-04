#include "InputDialog.h"
#include "PointData/PointData.h"

InputDialog::InputDialog(QWidget* parent, std::string& filePath) :
    QDialog(parent)
{
    setWindowTitle(tr("CSV Loader"));   
    std::string fullfileName = filePath.substr(filePath.find_last_of("/\\") + 1);
    _dataNameInput = new QLineEdit();
    _dataNameInput->setText(QString::fromStdString(fullfileName.substr(0, (fullfileName.find_last_of(".")))));

    _headerCheckbox = new QCheckBox("Has Headers");


    for (const char* const typeName : PointData::getElementTypeNames())
    {
        _dataTypeComboBox->addItem(QString::fromLatin1(typeName));
    }
    loadButton = new QPushButton(tr("Load file"));
    loadButton->setDefault(true);

    connect(loadButton, &QPushButton::pressed, this, &InputDialog::closeDialogAction);
    connect(this, &InputDialog::closeDialog, this, &QDialog::accept);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(_dataNameInput);
    layout->addWidget(_headerCheckbox);
    auto label = std::make_unique<QLabel>(tr("&Store as: "));
    label->setBuddy(_dataTypeComboBox);
    layout->addWidget(label.release());
    layout->addWidget(_dataTypeComboBox);
    layout->addWidget(loadButton);
    setLayout(layout);
}

void InputDialog::closeDialogAction()
{
    bool hasHeaders = _headerCheckbox->isChecked();
    emit closeDialog(_dataNameInput->text(), hasHeaders, _dataTypeComboBox->currentText());
}
