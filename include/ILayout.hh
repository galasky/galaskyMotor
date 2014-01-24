#ifndef	__ILAYOUT_HH__
#define	__ILAYOUT_HH__

class	ILayout
{
public:
  virtual ~ILayout() {}

  virtual void	draw() = 0;
private:
};

#endif
