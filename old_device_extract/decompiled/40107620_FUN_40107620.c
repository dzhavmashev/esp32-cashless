// Function : FUN_40107620
// Address  : 0x40107620
// Size     : 42 bytes


int FUN_40107620(void)

{
  int iVar1;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = 0xb33fffff;
  uStack_24 = 0;
  memw();
  iVar1 = (*(code *)&SUB_40083fe0)(8,0x804);
  if (iVar1 != 0) {
    (*(code *)&SUB_4008b3d0)(iVar1,&uStack_28);
  }
  return iVar1;
}

