// Function : FUN_40132570
// Address  : 0x40132570
// Size     : 218 bytes


/* WARNING: Type propagation algorithm not settling */

int FUN_40132570(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iStack_34;
  int aiStack_30 [12];
  
  iStack_34 = 1;
  aiStack_30[0] = 0;
  memw();
  iVar1 = FUN_40131798(param_3);
  uVar3 = iVar1 + 7;
  iVar4 = -4;
  if (-1 < param_2) {
    iVar2 = FUN_40131ad8(param_3,param_2);
    iVar4 = -4;
    if (0 < iVar2) {
      iVar2 = 0x1e;
      if (uVar3 < 0x28) {
        iVar2 = 0xfa;
      }
      aiStack_30[1] = 1;
      aiStack_30[2] = 0;
      aiStack_30[3] = 0;
      memw();
      iVar4 = FUN_401315c4(param_1,*(undefined4 *)(param_3 + 4));
      if (((iVar4 == 0) &&
          (iVar4 = FUN_40131574(aiStack_30 + 1,*(undefined4 *)(param_3 + 4)), iVar4 == 0)) &&
         (iVar4 = FUN_40131700(aiStack_30 + 1,param_2), iVar4 == 0)) {
        while( true ) {
          iVar4 = FUN_401314d4(param_1,uVar3 >> 3,param_4,param_5);
          if ((iVar4 != 0) ||
             (iVar4 = FUN_40131a34(param_1,(uVar3 & 0xfffffff8) - iVar1), iVar4 != 0))
          goto LAB_40132634;
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) break;
          iVar4 = FUN_4013373c(param_1,aiStack_30 + 1,&iStack_34);
          if (((iVar4 != 0) || (iVar4 = FUN_4013373c(param_1,param_3,aiStack_30), iVar4 != 0)) ||
             ((iStack_34 == 0 && (aiStack_30[0] != 0)))) goto LAB_40132634;
        }
        iVar4 = -0xe;
      }
LAB_40132634:
      memw();
      FUN_40131548(aiStack_30 + 1);
    }
  }
  return iVar4;
}

