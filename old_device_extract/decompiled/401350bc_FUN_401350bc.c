// Function : FUN_401350bc
// Address  : 0x401350bc
// Size     : 136 bytes


int FUN_401350bc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  iVar3 = param_2 + 0x18;
  iVar1 = FUN_40131ad8(iVar3,0);
  iVar2 = 0;
  if (iVar1 != 0) {
    FUN_40186008(auStack_38);
    FUN_40186008(auStack_2c);
    iVar2 = FUN_40132650(auStack_38,iVar3,param_1 + 4);
    if (((iVar2 == 0) && (iVar2 = FUN_40134f44(param_1,auStack_2c,auStack_38), iVar2 == 0)) &&
       (iVar2 = FUN_40134f44(param_1,param_2,param_2,auStack_2c), iVar2 == 0)) {
      param_2 = param_2 + 0xc;
      iVar2 = FUN_40134f44(param_1,param_2,param_2,auStack_2c);
      if ((iVar2 == 0) && (iVar2 = FUN_40134f44(param_1,param_2,param_2,auStack_38), iVar2 == 0)) {
        iVar2 = FUN_40131700(iVar3,1);
      }
    }
    FUN_40131548(auStack_38);
    FUN_40131548(auStack_2c);
  }
  return iVar2;
}

