#include "GPP/GPP.hpp"
#include "GPP_impl.hpp"
namespace gpp {
class text::Impl {
    std::string text_;

  public:
    Impl(const std::string &t);
    auto operator()(game &g) -> game &;
};
class image::Impl {
    std::string path_;

  public:
    Impl(const std::string &path);
    auto operator()(game &g) -> game &;
};
class bgm::Impl {
    std::string path_;

  public:
    Impl(const std::string &path);
    auto operator()(game &g) -> game &;
};
class pause::Impl {
  public:
    auto operator()(game &g) -> game &;
};
class clear::Impl {
  public:
    auto operator()(game &g) -> game &;
};
class game::Impl {
    friend text::Impl;
    friend image::Impl;
    friend bgm::Impl;
    friend pause::Impl;

  public:
    Impl(int argc, char **argv);
    Impl(int argc, char **argv, const std::string &title);
    Impl(int argc, char **argv, unsigned short w, unsigned short h);
    Impl(int argc, char **argv, const std::string &title, unsigned short w,
         unsigned short h);
    auto title(const std::string) -> Impl &;
    auto size(unsigned short w, unsigned short h) -> Impl &;
};
text::text(const std::string &t) : impl_{ new Impl{ t } } {}
text::~text() = default;
auto text::operator()(game &g) -> game &{ return (*impl_)(g); }
image::image(const std::string &path) : impl_{ new Impl{ path } } {}
image::~image() = default;
auto image::operator()(game &g) -> game &{ return (*impl_)(g); }
bgm::bgm(const std::string &path) : impl_{ new Impl{ path } } {}
bgm::~bgm() = default;
auto bgm::operator()(game &g) -> game &{ return (*impl_)(g); }
pause::pause() : impl_{ new Impl{} } {}
pause::~pause() = default;
auto pause::operator()(game &g) -> game &{ return (*impl_)(g); }
clear::clear() : impl_{ new Impl{} } {}
clear::~clear() = default;
auto clear::operator()(game &g) -> game &{ return (*impl_)(g); }
game::~game() = default;
text::Impl::Impl(const std::string &t) : text_{ t } {}
auto text::Impl::operator()(game &g) -> game &{ return g; }
image::Impl::Impl(const std::string &path) : path_{ path } {}
auto image::Impl::operator()(game &g) -> game &{ return g; }
bgm::Impl::Impl(const std::string &path) : path_{ path } {}
auto bgm::Impl::operator()(game &g) -> game &{ return g; }
auto pause::Impl::operator()(game &g) -> game &{ return g; }
auto clear::Impl::operator()(game &g) -> game &{ return g; }
int show_window(int argc, char **argv) {
    FXApp application("MainWindow", "MainWindow");
    application.init(argc, argv);
    new MainWindow(&application);
    application.create();
    return application.run();
}
}