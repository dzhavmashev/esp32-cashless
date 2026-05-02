// Function : FUN_4014d828
// Address  : 0x4014d828
// Size     : 215 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014d828(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (param_1 == (byte *)0x0) {
    FUN_40147fe4(1,2,1,"");
    uVar2 = 0x102;
  }
  else {
    bVar1 = *param_1;
    uVar2 = 0xffffffff;
    if ((bVar1 < 0x5c) && (*(int *)(param_1 + 4) != 0)) {
      if (((_DAT_3ffc8864 == 0) || (memw(), DAT_3ffc1a3c != '\0')) ||
         ((2 < (byte)(bVar1 - 0x34) && (0x18 < (byte)(bVar1 - 0x39))))) {
        FUN_40161498();
      }
      uVar2 = (**(code **)(param_1 + 4))(param_1);
      if (((_DAT_3ffc8864 == 0) || (memw(), DAT_3ffc1a3c != '\0')) ||
         ((2 < (byte)(*param_1 - 0x34) && (0x18 < (byte)(*param_1 - 0x39))))) {
        FUN_401615bc();
      }
    }
  }
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  if ((param_1[1] & 2) == 0) {
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
  }
  else if ((param_1[1] & 3) == 3) {
    if (*(int *)(param_1 + 0x10) == 0) {
      FUN_40147fe4(1,2,2,0x3f4367cd,*param_1);
    }
    else {
      (**(code **)(_DAT_3ffc1a34 + 0x40))();
    }
  }
  return uVar2;
}

