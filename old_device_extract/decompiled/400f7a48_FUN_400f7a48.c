// Function : FUN_400f7a48
// Address  : 0x400f7a48
// Size     : 638 bytes


int FUN_400f7a48(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5,uint param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  uint uStack_34;
  char acStack_28 [40];
  
  if (2 < param_1) {
    memw();
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar6 = "_select";
    uVar7 = 0x620;
LAB_400f7a6d:
    memw();
    FUN_4012113c(1,"th",pcVar6,uVar2,"th","_delete",uVar7);
    return -1;
  }
  if (param_2 < 0x81) {
    uVar2 = (*(code *)&SUB_40094b80)();
    uVar7 = 0x621;
    pcVar6 = " error\n";
    memw();
    goto LAB_400f7a6d;
  }
  if ((param_3 < 0x81) && (param_3 != 0)) {
    uVar2 = (*(code *)&SUB_40094b80)();
    uVar7 = 0x622;
    pcVar6 = " error\n";
    memw();
    goto LAB_400f7a6d;
  }
  uStack_34 = param_6;
  if ((param_6 & 0x400) != 0) {
    uStack_34 = param_6 & 0xfffffbff;
  }
  iVar5 = param_1 * 4;
  if (*(int *)(iVar5 + 0x3ffc5588) != 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar6 = " error\n";
    goto LAB_400f7b0f;
  }
  memw();
  piVar3 = (int *)(*(code *)&SUB_400841f0)(1,0xf4,0x1000);
  if (piVar3 == (int *)0x0) {
    *(int *)(iVar5 + 0x3ffc5588) = 0;
  }
  else {
    if (param_4 < 1) {
LAB_400f7b1e:
      if (0 < param_3) {
        iVar4 = (*(code *)&SUB_4008eb04)(param_3,0);
        piVar3[0x37] = iVar4;
        if (iVar4 == 0) {
          memw();
          goto LAB_400f7c7d;
        }
      }
      iVar4 = (*(code *)&SUB_4008eb04)(param_2,2);
      piVar3[0x36] = iVar4;
      memw();
      iVar4 = (*(code *)&SUB_4008fcc8)(1);
      piVar3[0x39] = iVar4;
      memw();
      iVar4 = (*(code *)&SUB_4008fcc8)(1);
      piVar3[0x38] = iVar4;
      memw();
      iVar4 = (*(code *)&SUB_4008f990)(1,0,3);
      piVar3[0x3c] = iVar4;
      memw();
      iVar4 = (*(code *)&SUB_4008f990)(1,0,3);
      piVar3[0x3b] = iVar4;
      memw();
      iVar4 = (*(code *)&SUB_4008f990)(1,0,3);
      piVar3[0x3a] = iVar4;
      if (((((piVar3[0x36] != 0) && (piVar3[0x38] != 0)) && (piVar3[0x39] != 0)) &&
          ((piVar3[0x3c] != 0 && (piVar3[0x3b] != 0)))) && (bVar1 = iVar4 == 0, !bVar1)) {
        piVar3[1] = param_4;
        piVar3[3] = 0;
        *(undefined2 *)(piVar3 + 4) = 0;
        piVar3[0x2f] = 0;
        piVar3[0x30] = 0;
        piVar3[0x31] = 0;
        *(undefined2 *)(piVar3 + 0x33) = 0;
        *(undefined1 *)((int)piVar3 + 0xce) = 0;
        piVar3[5] = 0;
        *(undefined1 *)(piVar3 + 7) = 0;
        *(undefined1 *)(piVar3 + 0x2e) = 0;
        memw();
        piVar3[0x2d] = param_3;
        piVar3[0x34] = 0;
        *piVar3 = param_1;
        piVar3[0x28] = 0x101;
        *(int *)(iVar5 + 0x3ffc5588) = (int)piVar3;
        memw();
        (*(code *)&SUB_4008fab8)(iVar4,0,bVar1,bVar1);
        FUN_400f6aa8(param_1,10);
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = *(undefined4 *)(*(int *)(iVar5 + 0x3ffc5588) + 0xd4);
          memw();
        }
        builtin_strncpy(acStack_28,"talled\n",8);
        memw();
        FUN_400f5ccc(param_1);
        iVar4 = *(int *)(param_1 * 0x10 + 0x3ffbdc78);
        memw();
        memw();
        *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & 0xfff80000;
        iVar5 = *(int *)(iVar5 + 0x3ffc5588);
        memw();
        *(undefined4 *)(iVar4 + 0x10) = 0x7ffff;
        memw();
        iVar5 = FUN_400f6de8(param_1,0x400f5d98,iVar5,uStack_34,iVar5 + 8);
        if ((iVar5 == 0) && (iVar5 = FUN_400f7254(param_1,acStack_28), iVar5 == 0)) {
          return 0;
        }
        FUN_400f7960(param_1);
        return iVar5;
      }
    }
    else {
      iVar4 = (*(code *)&SUB_4008f990)(param_4,0xc,0);
      piVar3[0x35] = iVar4;
      if (iVar4 != 0) goto LAB_400f7b1e;
    }
LAB_400f7c7d:
    memw();
    FUN_400f6584(piVar3);
    *(undefined4 *)(iVar5 + 0x3ffc5588) = 0;
    memw();
  }
  memw();
  uVar2 = (*(code *)&SUB_40094b80)();
  pcVar6 = " error\n";
LAB_400f7b0f:
  FUN_4012113c(1,"th",pcVar6,uVar2,"th");
  return -1;
}

