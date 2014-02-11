#ifndef	__ILAYOUT_HH__
#define	__ILAYOUT_HH__

class	ILayout
{
public:
  virtual ~ILayout() {}

  virtual void	draw() = 0;
  virtual void	down() = 0;
  virtual void	up() = 0;
  virtual void	enter() = 0;
  virtual void	mouseMoved() = 0;
  virtual void	click() = 0;
private:
};

#endif
