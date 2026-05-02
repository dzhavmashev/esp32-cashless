// Function : FUN_40138df0
// Address  : 0x40138df0
// Size     : 62 bytes


int FUN_40138df0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4013905c(param_1,param_2,1);
  if (iVar1 == 0) {
    uVar2 = FUN_401864c4(param_2);
    iVar1 = FUN_40139270(param_1,param_1 + 0xc,uVar2);
    if (iVar1 == 0) {
      uVar2 = FUN_401864c4(param_2);
      (*(code *)&SUB_4008b530)(param_1 + 0xc,1,uVar2);
      iVar1 = FUN_40138c20(param_1,param_3,param_4);
    }
  }
  return iVar1;
}

