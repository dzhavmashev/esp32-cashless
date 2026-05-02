// Function : FUN_4015aa08
// Address  : 0x4015aa08
// Size     : 106 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015aa08(char param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (param_1 == '\0') {
    uVar1 = *param_2;
    if ((uVar1 & 0xfeff) == 0x400) {
      uVar1 = uVar1 >> 8;
    }
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 4) {
      memw();
      uVar2 = 0x3ffc7a99;
      memw();
    }
    else {
      if (uVar1 != 5) {
        return 0xffffffff;
      }
      uVar2 = 0x3ffc7ac1;
      memw();
    }
    memw();
    _DAT_3ffbfd54 = uVar1;
    (*(code *)&SUB_4008b3d0)(uVar2,param_2,0x28);
  }
  return 0;
}

