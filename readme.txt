唔…
很抱歉把这么一个连半成品都说不上的东西拿出来…
但是这个事的工程量实在有一点大——而且与我的兴趣范围交集并不大。

先来说说这个工程的由来吧。
实际上就是一次我无法辩解的违规复制——试图与一个无法物理接触到的同学分享一部游戏。
很幸运地，那个游戏动态调用了steam_api.dll作为与steam的通信手段，因此我得以进行一些“小动作”。
比如说，制作一个假的steam_api.dll来接管需要用到的函数。
这就是这一部分代码的由来。

不得不说，虽然steam的文档写的令人难以抑制吐槽的冲动，但是作为核心的Call Result和Callbacks两部分还是设计的蛮简洁的。也是得益于此，终于在断断续续搞了将近一周的时间后，结合头文件和文档猜测出了其中的一部分构造，并实现了一部分文件操作函数…

嘛…暂时就咕了吧，毕竟我想要分享的游戏看似已经可以完美运行了。

22:55 2019/9/22 于宿舍