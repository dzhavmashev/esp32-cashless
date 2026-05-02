// Function : FUN_40134fec
// Address  : 0x40134fec
// Size     : 71 bytes


int FUN_40134fec(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_2c);
  iVar1 = FUN_40132570(auStack_2c,2,param_1 + 4,param_3,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_40134f44(param_1,param_2,param_2,auStack_2c), iVar1 == 0)) {
    iVar1 = FUN_40134f44(param_1,param_2 + 0x18,param_2 + 0x18,auStack_2c);
  }
  FUN_40131548(auStack_2c);
  if (iVar1 == -0xe) {
    iVar1 = -0x4d00;
  }
  return iVar1;
}

