// Function : FUN_40158fe4
// Address  : 0x40158fe4
// Size     : 162 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40158fe4(undefined4 param_1)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  
  bVar2 = DAT_3ffc89c4;
  iVar1 = _DAT_3ffc8800;
  uVar3 = 0x3007;
  if (_DAT_3ffc8800 != 0) {
    uVar4 = *(uint *)(_DAT_3ffc8800 + 0x154) & 0x200;
    uVar3 = 0;
    if (uVar4 == 0) {
      if (_DAT_3ffc89a4 != (undefined4 *)0x0) {
        _DAT_3ffc8924 = &DAT_3ffc8920;
        memw();
        _DAT_3ffc8920 = uVar4;
        (*(code *)*_DAT_3ffc89a4)();
      }
      FUN_401677dc();
      FUN_40147fe4(1,1,3,0x3f43500a);
      FUN_4015fc30(0,0,param_1,0,bVar2 >> 4 & 1,DAT_3ffc89c0);
      FUN_40147fe4(1,4,4,0x3f433bdb,*(undefined1 *)(_DAT_3ffc8800 + 0x154),0);
      *(undefined1 *)(_DAT_3ffc8800 + 0x154) = 0;
      memw();
      *(byte *)(iVar1 + 0x155) = *(byte *)(iVar1 + 0x155) | 2;
      memw();
      memw();
      FUN_40147240(2,0);
      uVar3 = 0;
    }
  }
  return uVar3;
}

