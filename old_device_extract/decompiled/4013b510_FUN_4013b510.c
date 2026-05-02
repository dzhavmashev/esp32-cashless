// Function : FUN_4013b510
// Address  : 0x4013b510
// Size     : 99 bytes


int FUN_4013b510(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_2c [44];
  
  iVar1 = FUN_4013b074(param_1,0);
  iVar2 = -0x4080;
  if (iVar1 == 0) {
    FUN_40186008(auStack_2c);
    iVar2 = FUN_4013183c(auStack_2c,param_2,*(undefined4 *)(param_1 + 4));
    if (iVar2 == 0) {
      iVar1 = FUN_401860ec(auStack_2c,param_1 + 8);
      iVar2 = -4;
      if (iVar1 < 0) {
        uVar3 = *(undefined4 *)(param_1 + 4);
        iVar2 = FUN_4013d3d8(auStack_2c,auStack_2c,param_1 + 0x14,param_1 + 8,param_1 + 0x68);
        if (iVar2 == 0) {
          iVar2 = FUN_40131900(auStack_2c,param_3,uVar3);
        }
      }
    }
    FUN_40131548(auStack_2c);
    if (iVar2 != 0) {
      iVar2 = iVar2 + -0x4280;
    }
  }
  return iVar2;
}

