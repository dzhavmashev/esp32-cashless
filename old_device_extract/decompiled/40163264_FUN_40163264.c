// Function : FUN_40163264
// Address  : 0x40163264
// Size     : 346 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40163264(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  char *pcVar6;
  
  uVar2 = FUN_40165f04();
  cVar1 = (**(code **)(_DAT_3ffc1a34 + 0xa8))();
  if (_DAT_3ffc7bf8 != 0) {
    FUN_40147fe4(6,1,2,0x3f43702c);
    (**(code **)(_DAT_3ffc1a34 + 0x98))(_DAT_3ffc7bf8);
  }
  if (_DAT_3ffc7be8 != (int *)0x0) {
    FUN_40147fe4(6,1,2,0x3f43700b);
    (**(code **)(_DAT_3ffc1a34 + 0x180))(_DAT_3ffc7be8);
  }
  _DAT_3ffc7be8 = (int *)(**(code **)(_DAT_3ffc1a34 + 0x17c))(200,8);
  if (_DAT_3ffc7be8 == (int *)0x0) {
    memw();
    FUN_40147fe4(6,1,1,"e queue");
  }
  else {
    _DAT_3ffc1ac8 = *_DAT_3ffc7be8;
    pcVar6 = "ate sem";
    if (_DAT_3ffc1ac8 != 0) {
      memw();
      _DAT_3ffc7bf0 = (**(code **)(_DAT_3ffc1a34 + 0x34))(1,0);
      pcVar6 = "te task";
      if (_DAT_3ffc7bf0 != 0) {
        pcVar5 = *(code **)(_DAT_3ffc1a34 + 0x90);
        memw();
        uVar3 = FUN_40165ee0();
        memw();
        iVar4 = (**(code **)(_DAT_3ffc1a34 + 0xa8))();
        memw();
        iVar4 = (*pcVar5)(&PTR_s_cess_40189310,"g state",uVar3,0,iVar4 + -2,&DAT_3ffc7bf8,uVar2);
        if (iVar4 == 1) {
          (**(code **)(_DAT_3ffc1a34 + 0x3c))(_DAT_3ffc7bf0,0xffffffff);
          (**(code **)(_DAT_3ffc1a34 + 0x9c))(1);
          (**(code **)(_DAT_3ffc1a34 + 0x38))(_DAT_3ffc7bf0);
          iVar4 = _DAT_3ffc7bf8;
          _DAT_3ffc7bf0 = 0;
          memw();
          uVar3 = FUN_40165ee0();
          memw();
          FUN_40147fe4(6,1,3,0x3f435aa4,iVar4,cVar1 + -2,uVar3,uVar2);
          return 0;
        }
        pcVar6 = "";
      }
    }
    FUN_40147fe4(6,0x800,1,pcVar6);
    if (_DAT_3ffc7be8 != (int *)0x0) {
      (**(code **)(_DAT_3ffc1a34 + 0x180))();
      _DAT_3ffc7be8 = (int *)0x0;
    }
    if (_DAT_3ffc7bf0 != 0) {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0x38))();
    }
    _DAT_3ffc7bf8 = 0;
  }
  memw();
  return 0x101;
}

