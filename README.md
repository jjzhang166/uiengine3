#UIEngine
/*
    cBaseUI
    所有UI类的基类
    */
    class cBaseUI
    {
    public:
        cBaseUI();
        /*
        有参构造函数
        @Param :
            int x：ui控件x坐标
            int y : ui控件y坐标
        */
        explicit cBaseUI(const int& x, const int& y);
        virtual ~cBaseUI();

        /*
        SetX(const int& x);
        设置ui控件x坐标
        @Param ：
            int x：新的x坐标
        */
        void SetX(const int& x);

        /*
        GetX()
        获取ui控件x坐标
        @return const int&:
            ui控件当前x坐标
        */
        const int& GetX() const;

        /*
        SetY(const int& y)
        设置ui控件y坐标
        @Param ：
            int y:新的y坐标
        */
        void SetY(const int& y);

        /*
        GetY()
        获取ui控件当前y坐标
        @return int：
            当前y坐标
        */
        const int& GetY() const;

        /*
        GetRect()
        获取ui控件一个矩形区域
        @return RECT：
            ui控件的矩形区域
        */
        virtual const RECT GetRect() const=0;

        /*
        Draw(HDC hDc)
        绘制ui控件
        @Param:
            HDC hDc:设备DC
        */
        virtual bool Draw(HDC hDc) = 0;
    private:
        int m_x;
        int m_y;
    }；

    /*
    cAmination
    动画
    */
    class cAmination:public cBaseUI
    {
    public:
        cAmination();

        /*
        构造函数，初始化的动画资源，并自定其宽度和高度也可以使用图片本身默认宽高
        @Param：
            std::initializer_list<LPWSTR> initList:动画资源路径列表
            int w：动画宽度
            int h：动画高度
        */
        explicit cAmination(const std::initializer_list<LPWSTR>& initlist,const int& w=0,const int& h=0);
        
        ~cAmination();

        /*
        SetAmination(const std::initializer_list<LPWSTR>& initlist,const int& x,const int& y)
        初始化的动画资源，并自定义其宽度和高度也可以使用图片本身默认宽高
        @Param：
            std::initializer_list<LPWSTR> initlist:动画资源路径列表
            int w：动画宽度
            int h：动画高度
        */
        void SetAmination(const std::initializer_list<LPWSTR>& initlist,const int& w=0,const int& h=0);

        /*
        GetAmination()
        获取动画资源位图句柄列表
        @return std::vector<HBITMAP>：
            动画资源位图句柄列表
        */
        const std::vector<HBITMAP>& GetAmination() const;

        /*
        GetRect()
        获取ui控件一个矩形区域
        @return RECT：
        ui控件的矩形区域
        */
        virtual const RECT GetRect() const override;

        /*
        Draw(HDC hDc)
        绘制ui控件
        @Param:
        HDC hDc:设备DC
        */
        virtual bool Draw(HDC hDc)  override;

        /*
        SetIsLucency(const BOOL& b)
        设置动画是否具有透明色
        @Param：
            BOOL b：TRUE表示具有透明色FALSE表示不具有透明色
        */
        void SetIsLucnecy(const BOOL& b);

        /*
        GetIsLucency()
        获取动画是否具有·透明
        @return BOOL：
            TRUE：动画具有透明色
            FALSE：动画不具有透明色
        */
        const BOOL& GetIsLucency() const;

        /*
        SetLucencyColor()
        设置透明色
        @Param：
            UINT rgb：透明rgb色
        */
        void SetLucnecyColor(const UINT& rgb);

        /*
        GetLucencyColor()
        获取透明色
        @return UINT：
            透明rgb色
        */
        const UINT& GetLucnecyColor() const;

        /*
        GetConfig()
        获取动画信息
        @return BITMAP：
            动画图片信息
        */
        const BITMAP& GetConfig() const;

        /*
        IncCurFrame()
        自增当前帧
        */
        void IncFrame();

        /*
        SetAutoRun(const BOOL& b)
        设置是否自动播放
        @Param：
            BOOL b：是否自动播放
        */
        void SetAutoRun(const BOOL& b);

        /*
        IsAutoRun()
        是否自动播放
        */
        const BOOL& IsAutoRun() const;
    private:
        /*
        SetAmiConfig()
        设置动画配置
        */
        void InitAmiConfig();

        /*
        DeleteAmination()
        删除动画位图资源
        */
        void DeleteAmination();
    
        //动画位图资源句柄列表
        std::vector<HBITMAP> m_Amination;

        //动画是否有透明色
        BOOL m_isLucency;

        //动画透明rgb色
        UINT m_lucencyRgb;

        //保存位图句柄信息
        BITMAP m_amiConfig;

        unsigned m_maxFrame;

        unsigned m_curFrame;

        BOOL m_isAutoRun;
    };



     //用于标记按钮状态
    enum Btn_Status
    {
        Get_Focus,   //获取得焦点
        Lost_Focus,   //失去焦点
        Mouse_Up,   //鼠标点击
        Mouse_Down,   //鼠标弹起
    };

    /*
    cButton
    按钮
    */
    class cButton :public cBaseUI
    {
    public:
        cButton();

        /*
        有参构造函数，初始化按钮名称和宽高
        @Param:
            LPWSTR Name:按钮名称
            int width:按钮宽度
            int height：按钮高度
        */
        explicit cButton(const LPWSTR& Name,const int& width,const int& height);

        /*
        有参构造函数，以图片初始化按钮
        @Param LPWSTR：
            LPWSTR bmpPath:图片路径
        */
        explicit cButton(const LPWSTR& bmpPath);

        /*
        有参构造函数，以图片初始化按钮
        @Param LPWSTR：
            HBITMAP hbitmap:位图句柄
        */
        explicit cButton(const HBITMAP& hbitmap);

        virtual ~cButton();

        /*
        SetName()
        设置按钮名称
        @Param：
            LPWSTR name:按钮名
        */
        void SetName(const LPWSTR& Name);

        /*
        GetName()
        获取按钮名
        @return LPWSTR：
            按钮名
        */
        const LPWSTR& GetName() const;

        /*
        SetWidth(const int& width)
        设置按钮宽度
        @Param：
            int width：按钮宽度
        */
        void SetWidth(const int& width);

        /*
        GetWidth()
        获取按钮宽度
        @return int：
            按钮宽度
        */
        const int& GetWidth() const;

        /*
        SetHeight(const int& height)
        设置按钮高度
        @Param：
            int height：按钮高度
        */
        void SetHeight(const int& Height);

        /*
        GetHeight()
        获取按钮高度
        @return int：
            按钮高度
        */
        const int& GetHeight() const;

        /*
        SetBount(const int& n)
        设置按钮边框宽度
        @Param：
            int n：按钮边框宽度
        */
        void SetnBount(const int& n);

        /*
        GetBount()
        获取按钮边框宽度
        @return int：
            按钮边框宽度
        */
        const int& GetBount() const;

        /*
        SetBountColor(const UINT& rgb)
        设置边框颜色
        @Param：
            UINT rgb：边框颜色
        */
        void SetBountColor(const UINT& rgb);

        /*
        GetBountColor()
        获取按钮边框颜色
        @return UINT：
            按钮边框颜色
        */
        const UINT& GetBountColor() const;

        /*
        SetFirstColor(const UINT& rgb)
        设置按钮第一颜色
        @Param:
            UINT rgb:RGB色
        */
        void SetfirstColor(const UINT& rgb);

        /*
        GetFirstColor()
        获取按钮第一颜色
        @return UINT:
            按钮第一颜色
        */
        const UINT& GetfirstColor() const;

        /*
        SetSecondColor(const UINT& rgb)
        设置第二颜色
        @Param：
            UINT rgb：RGB色
        */
        void SetsecondColor(const UINT& rgb);

        /*
        GetsecondColor()
        获取按钮第二颜色
        @return UINT：
            按钮第二颜色
        */
        const UINT& GetsecondColor() const;

        /*
        GetRect()
        获取ui控件一个矩形区域
        @return RECT：
            ui控件的矩形区域
        */
        virtual const RECT GetRect() const override;

        /*
        Draw(HDC hDc)
        绘制ui控件
        @Param:
            HDC hDc:设备DC
        */
        virtual bool Draw(HDC hDc) override;

        /*
        DrawNormal(HDC hDc)
        绘制无背景图片的按钮
        @Param：
            HDC hDc：窗口设备DC
        */
        bool DrawNormal(HDC hDc);

        /*
        DrawBitmapBtn
        绘制背景图片按钮
        @Param：
            HDC hDc：窗口设备DC
        */
        bool DrawBitmapBtn(HDC hDc);

        /*
        SetFont(const LPWSTR& font);
        设置字体
        @Param：
            LPWSTR font：字体
        */
        void SetFont(const LPWSTR& font);

        /*
        GetFont()
        获取按钮文本字体
        @return LPWSTR：
            按钮文本字体
        */
        const LPWSTR& GetFont() const;

        /*
        SetFontColor()
        设置字体颜色
        @Param：
            UINT rgb：rgb色
        */
        void SetFontColor(const UINT& rgb);

        /*
        GetFontColor()
        获取字体颜色
        @return UINT：
            字体颜色
        */
        const UINT& GetFontColor() const;

        /*
        ChangeColor()
        改变按钮背景色,当按钮得到和失去焦点时会改变背景色
        @Param:
            BtnFocus focus：按钮得到或失去焦点
        */
        void ChangeColor(Btn_Status focus);

        /*
        ChangeBountColor()
        当鼠标按下和弹起时改变按钮边框颜色
        @param：
            Btn_Status clicked:鼠标是否按下
        */
        void ChangeBountColor(Btn_Status clicked);

        /*
        SetBmpBtn(const LPWSTR& bmpPath)
        设置按钮背景图片
        @Param：
            LPWSTR bmpPath：图片路径
        */
        void SetBmpBtn(const LPWSTR& bmpPath);

        /*
        SetBmpBtn(const HBITMAP& hbitmap)
        设置按钮背景图片
        @Param：
            HBITMAP hbitmap：位图句柄
        */
        void SetBmpBtn(const HBITMAP& hbitmap);
    private:
        LPWSTR m_Name;

        int m_width;

        int m_height;

        //边框宽度
        int m_nBount;

        UINT m_BountColor;

        UINT m_firstBountColor;

        UINT m_secBountColor;

        //按钮为未获取得焦点时的背景色
        UINT m_firstColor;

        //按钮获取焦点时的背景色
        UINT m_secondColor;

        LPWSTR m_font;

        UINT m_fontColor;

        UINT m_bgColor;

        HBITMAP m_bgBitmap;
    };
