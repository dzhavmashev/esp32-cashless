// Function : FUN_400f7574
// Address  : 0x400f7574
// Size     : 316 bytes


int FUN_400f7574(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int aiStack_24 [9];
  
  if (param_1 < 3) {
    if (param_2 == 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar7 = 0x526;
      pcVar6 = " error\n";
      memw();
    }
    else {
      piVar4 = (int *)(param_1 * 4 + 0x3ffc5588);
      if (*piVar4 != 0) {
        aiStack_24[0] = 0;
        memw();
        iVar2 = (*(code *)&SUB_40090010)(*(undefined4 *)(*piVar4 + 0xe0),param_4);
        iVar5 = 0;
        if (iVar2 != 1) {
          return -1;
        }
        iVar2 = param_1 * 0x10 + 0x3ffbdc7c;
        do {
          while( true ) {
            if (param_3 == 0) goto LAB_400f7640;
            memw();
            iVar3 = (*(code *)&SUB_4008ed94)
                              (*(undefined4 *)(*piVar4 + 0xd8),aiStack_24,param_4,param_3);
            if (iVar3 == 0) break;
            memw();
            (*(code *)&SUB_4008b3d0)(param_2 + iVar5,iVar3,aiStack_24[0]);
            (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
            *(int *)(*piVar4 + 0x14) = *(int *)(*piVar4 + 0x14) - aiStack_24[0];
            memw();
            FUN_400f5c34(param_1);
            (*(code *)&SUB_40092bec)(iVar2);
            iVar5 = iVar5 + aiStack_24[0];
            param_3 = param_3 - aiStack_24[0];
            (*(code *)&SUB_4008edec)(*(undefined4 *)(*piVar4 + 0xd8),iVar3);
            FUN_400f666c(param_1);
          }
          iVar3 = FUN_400f666c(param_1);
        } while (iVar3 != 0);
LAB_400f7640:
        (*(code *)&SUB_4008fab8)(*(undefined4 *)(*(int *)(param_1 * 4 + 0x3ffc5588) + 0xe0),0,0);
        return iVar5;
      }
      memw();
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar7 = 0x527;
      pcVar6 = " error\n";
      memw();
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar6 = "_select";
    uVar7 = 0x525;
  }
  memw();
  FUN_4012113c(1,"th",pcVar6,uVar1,"th","tr_mask",uVar7);
  return -1;
}

