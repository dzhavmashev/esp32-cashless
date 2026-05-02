// Function : FUN_40161ea4
// Address  : 0x40161ea4
// Size     : 371 bytes


/* WARNING: Removing unreachable block (ram,0x40161f61) */
/* WARNING: Removing unreachable block (ram,0x40161f1f) */
/* WARNING: Removing unreachable block (ram,0x40161fbc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_40161ea4(char param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined1 local_30 [48];
  
  local_30[0] = 0;
  memw();
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    uVar2 = 0;
    if (DAT_3ffca1da == param_1) {
      FUN_4018c018();
      uVar6 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      if (DAT_3ffca1e5 == '\0') {
        iVar3 = FUN_40161a3c((int)uVar6,(int)(uVar6 >> 0x20),5000);
        uVar2 = local_30[0];
        if (iVar3 != 0) {
          if (uVar6 < CONCAT44(_DAT_3ffca23c,_DAT_3ffca238)) {
            (**(code **)(_DAT_3ffc1a34 + 0x19c))(1,0,_DAT_3ffca238 - (int)uVar6);
          }
          FUN_40161194();
          uVar2 = local_30[0];
        }
      }
      else {
        FUN_40161150();
        uVar6 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
        cVar1 = DAT_3ffca1d9;
        uVar5 = (undefined4)(uVar6 >> 0x20);
        iVar3 = (int)uVar6;
        if (DAT_3ffca1d9 == '\x01') {
          iVar4 = FUN_40161a3c(iVar3,uVar5,5000);
          if (iVar4 == 0) {
            DAT_3ffca1f1 = cVar1;
          }
          else {
            if ((uVar6 < CONCAT44(_DAT_3ffca23c,_DAT_3ffca238)) && (DAT_3ffca1e6 != '\0')) {
              (**(code **)(_DAT_3ffc1a34 + 0x19c))(1,0,_DAT_3ffca238 - iVar3);
            }
            if (((DAT_3ffca1eb == '\0') && (DAT_3ffca1e6 != '\0')) && (DAT_3ffca1e7 == '\0')) {
              FUN_401613ec();
            }
          }
          local_30[0] = 1;
          memw();
          memw();
          uVar2 = local_30[0];
        }
        else if (DAT_3ffca1d9 == '\x02') {
          iVar4 = FUN_40161a3c(iVar3,uVar5,5000);
          if (iVar4 == 0) {
            DAT_3ffca1f1 = '\x01';
            memw();
          }
          else {
            if ((uVar6 < CONCAT44(_DAT_3ffca23c,_DAT_3ffca238)) && (DAT_3ffca1e6 != '\0')) {
              (**(code **)(_DAT_3ffc1a34 + 0x19c))(1,0,_DAT_3ffca238 - iVar3);
            }
            FUN_4018bdc0();
            if (((DAT_3ffca1eb == '\0') && (DAT_3ffca1e6 != '\0')) && (DAT_3ffca1e7 == '\0')) {
              FUN_401613ec();
            }
          }
          local_30[0] = 1;
          memw();
          _DAT_3ffc7c28 = _DAT_3ffc7c28 + 1;
          memw();
          uVar2 = local_30[0];
        }
        else {
          uVar2 = local_30[0];
          if (DAT_3ffca1d9 == '\0') {
            FUN_4018a8a8();
            uVar2 = local_30[0];
          }
        }
      }
    }
  }
  else {
    memw();
    (*_DAT_3ffc7a28)(local_30);
    uVar2 = local_30[0];
  }
  return uVar2;
}

