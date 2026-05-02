// Function : FUN_400f9c84
// Address  : 0x400f9c84
// Size     : 79 bytes


undefined4
FUN_400f9c84(int param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,int *param_5,
            undefined4 param_6,undefined1 param_7,undefined1 param_8)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 auStack_24 [9];
  
  iVar1 = *(int *)(param_1 + 0x10);
  do {
    if (iVar1 == 0) {
      uVar3 = 0x1102;
LAB_400f9cc1:
      memw();
      return uVar3;
    }
    auStack_24[0] = 0;
    memw();
    iVar2 = FUN_400fb6ac(iVar1,param_2,param_3,param_4,auStack_24,param_6,param_7,param_8);
    if (iVar2 == 0) {
      *param_5 = iVar1;
      uVar3 = 0;
      goto LAB_400f9cc1;
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}

