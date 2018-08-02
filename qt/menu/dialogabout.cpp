#include "dialogabout.h"
#include "ui_dialogabout.h"

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);

    Qt::WindowFlags flag = Qt::Dialog;
    flag |= Qt::WindowCloseButtonHint;
    flag |= Qt::MSWindowsFixedSizeDialogHint;
    setWindowFlags(flag);

//    QLabel *pLabel = new QLabel(this);
//    pLabel->setOpenExternalLinks(true);
//    pLabel->setText(tr("<a href=\"www.eastups.com\">打开官网：http://www.eastups.com</a>"));

//    pLabel->setText("<font color=\"#FF0000\">RED</font><br><font color=\"#0000FF\">BLUE</font>"); //红\n蓝
//    pLabel->setText("<font color=\"#FF0000\">RED</font><font color=\"#0000FF\"> BLUE</font>"); //红 蓝
//    pLabel->setText("<font color=\"#ff0000\"><i>RED</i></font>"); //红（斜）
//    pLabel->setText("<font color=\"#ff0000\" size=10><i>RED</i></font>"); //红（字号斜）
//    pLabel->setText("<font color=\"#FF0000\">RED</font><sup>super</sup><font color=\"#0000FF\"> BLUE</font><sub>sub</sub>"); //红(上标) 蓝(下标)

    /*
        原始码 呈现结果
        <b>粗体</b> 粗体
        <i>斜体</i> 斜体
        <u>底线</u> 底线
        <sup>上标</sup> 上标
        <sub>下标</sub> 下标
        <tt>打字机</tt> 打字机
        <blink>闪烁</blink>（ie没效果） 闪烁
        <em>强调</em> 强调
        <strong>加强</strong> 加强
        <samp>范例</samp> 范例
        <code>原始码</code> 原始码
        <var>变数</var> 变数
        <dfn>定义</dfn> 定义
        <cite>引用</cite> 引用
        <address>所在地址</address> 所在地址

        <font color="#ff0000">红</font> 红色的字喔！
        <font color="#ff8000">橙</font> 橙色的字喔！
        <font color="#ffff00">黄</font> 黄色的字喔！
        <font color="#00ff00">绿</font> 绿色的字喔！
        <font color="#0080ff">蓝</font> 蓝色的字喔！
        <font color="#0000a0">靛</font> 靛色的字喔！
        <font color="#8000ff">紫</font> 紫色的字喔！
        <font color="#000000">黑</font> 黑色的字喔！
        <font color="#c0c0c0">灰</font> 灰色的字喔！
        */
    //    pLabel->setText("<em>No</em>"); //不(强调)
    //    pLabel->setText("<strong>No</strong>"); //不(加强)
    //    pLabel->setText("<samp>No</samp>"); //不(范例)

    //blink功能不行，多数是支持的

}

DialogAbout::~DialogAbout()
{
    delete ui;
}
