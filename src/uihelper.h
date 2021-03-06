#ifndef UIHELPER_H
#define UIHELPER_H

#include <QtCore/QObject>
#include <QtCore/QString>

class UIHelper : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool darkTheme READ darkTheme NOTIFY darkThemeChanged)
    Q_PROPERTY(int  screenDpi READ screenDpi NOTIFY screenDpiChanged)

private:
    explicit UIHelper(QObject *parent = nullptr);
    ~UIHelper() noexcept override = default;

public:
    UIHelper(const UIHelper &) = delete;
    UIHelper(UIHelper &&) noexcept = delete;

    UIHelper &operator=(const UIHelper &) = delete;
    UIHelper &operator=(UIHelper &&) noexcept = delete;

    static UIHelper &GetInstance();

    bool darkTheme() const;
    int screenDpi() const;

    Q_INVOKABLE bool requestReadStoragePermission() const;
    Q_INVOKABLE bool requestWriteStoragePermission() const;

    Q_INVOKABLE void showGallery() const;
    Q_INVOKABLE void shareImage(const QString &image_path) const;

public slots:
    void handleDeviceConfigurationUpdate();
    void handleImageSelection(const QString &image_path, int image_orientation);
    void handleImageSelectionCancel();
    void handleImageSelectionFailure();

signals:
    void darkThemeChanged(bool darkTheme);
    void screenDpiChanged(int screenDpi);
    void imageSelected(const QString &imagePath, int imageOrientation);
    void imageSelectionCancelled();
    void imageSelectionFailed();

private:
    bool DarkTheme;
    int  ScreenDpi;
};

#endif // UIHELPER_H
