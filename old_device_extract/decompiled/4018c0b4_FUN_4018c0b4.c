// Function : FUN_4018c0b4
// Address  : 0x4018c0b4
// Size     : 346 bytes


/* WARNING: Removing unreachable block (ram,0x4018c17e) */
/* WARNING: Removing unreachable block (ram,0x4018c101) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

ulonglong FUN_4018c0b4(char param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar2 = FUN_4018c040();
  cVar1 = DAT_3ffca1d9;
  if (DAT_3ffca1d9 == '\x01') {
    if (param_1 != '\0') {
      memw();
      uVar7 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      iVar4 = (int)uVar7;
      iVar3 = FUN_40161a3c(iVar4,(int)(uVar7 >> 0x20),5000);
      if (iVar3 == 0) {
        DAT_3ffca1f1 = cVar1;
        memw();
        memw();
        return CONCAT44(iVar4,&DAT_3ffc1a34);
      }
      DAT_3ffca1ea = cVar1;
      memw();
      if (uVar7 < CONCAT44(_DAT_3ffca23c,_DAT_3ffca238)) {
        memw();
        (**(code **)(_DAT_3ffc1a34 + 0x19c))(1,0,_DAT_3ffca238 - iVar4);
      }
      FUN_4016179c();
      _DAT_3ffc7c18 = _DAT_3ffc7c18 + 1;
      memw();
      return CONCAT44(&DAT_3ffc7c10,_DAT_3ffc7c18);
    }
    if ((param_2 & 0xff) == 0) {
      uVar7 = (ulonglong)CONCAT14(DAT_3ffca1eb,param_2) & 0xffffffff000000ff;
      DAT_3ffca1ea = (char)param_2;
      memw();
      if ((DAT_3ffca1eb == '\0') &&
         (uVar7 = (ulonglong)CONCAT14(DAT_3ffca1ec,param_2) & 0xffffffff000000ff, DAT_3ffca1ec == 0)
         ) {
        memw();
        FUN_4018bca8();
        if (uVar2 == 0) {
          FUN_4018be94();
          return ((ulonglong)param_2 & 0xff) << 0x20;
        }
        FUN_401613ec(1);
        return CONCAT44(param_2,uVar2) & 0xffffffffff;
      }
    }
    else {
      memw();
      uVar7 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      iVar3 = (int)(uVar7 >> 0x20);
      iVar4 = FUN_40161a3c((int)uVar7,iVar3,1000);
      if (iVar4 != 0) {
        DAT_3ffca1ea = cVar1;
        memw();
        memw();
        FUN_4018b360();
        if (uVar7 < CONCAT44(_DAT_3ffca23c,_DAT_3ffca238)) {
          uVar5 = _DAT_3ffca238 - (int)uVar7;
          uVar6 = _DAT_3ffca20c;
          if (_DAT_3ffca23c - iVar3 == (uint)(_DAT_3ffca238 < uVar5)) {
            uVar6 = (_DAT_3ffca20c < uVar5) * _DAT_3ffca20c + (_DAT_3ffca20c >= uVar5) * uVar5;
          }
          (**(code **)(_DAT_3ffc1a34 + 0x19c))(2,0,uVar6);
        }
        if ((DAT_3ffca1eb == '\0') && (DAT_3ffca1ec < uVar2)) {
          FUN_401613ec(1);
        }
        _DAT_3ffc7c1c = _DAT_3ffc7c1c + 1;
        memw();
        return CONCAT44(&DAT_3ffc7c10,_DAT_3ffc7c1c);
      }
    }
  }
  else {
    uVar7 = (ulonglong)CONCAT14(param_1,param_2) & 0xffffffff000000ff;
    if (((param_2 & 0xff) == 0 && DAT_3ffca1d9 == '\0') &&
       (uVar7 = (ulonglong)CONCAT14(param_1,param_2) & 0xffffffff000000ff, param_1 == '\0')) {
      memw();
      DAT_3ffca1ea = 0;
      uVar7 = (ulonglong)CONCAT14(param_1,param_2) & 0xffffffff000000ff;
    }
  }
  memw();
  return CONCAT44((int)uVar7,(int)(uVar7 >> 0x20));
}

