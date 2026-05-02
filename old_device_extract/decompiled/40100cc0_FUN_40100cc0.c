// Function : FUN_40100cc0
// Address  : 0x40100cc0
// Size     : 189 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40100cc0(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_38;
  int iStack_34;
  undefined1 auStack_30 [12];
  undefined1 uStack_24;
  
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0xc4);
    piVar2 = *(int **)(iVar3 + 8);
    iVar5 = *(int *)(param_1 + 4);
    if (iVar5 == 0) {
      if (*piVar2 != 0) {
        FUN_40100b38(iVar3);
      }
    }
    else {
      iVar7 = *(int *)(param_1 + 0x1c);
      iVar6 = *(int *)(param_1 + 0x34);
      if (((iVar5 != *piVar2) || (piVar2[1] != iVar7)) || (piVar2[2] != iVar6)) {
        uVar1 = *(undefined4 *)(iVar3 + 0xc);
        (*(code *)&SUB_4008b530)(auStack_30,0);
        uStack_38 = 0xffffffff;
        uVar4 = *(undefined4 *)(iVar3 + 0x40);
        *piVar2 = iVar5;
        piVar2[1] = iVar7;
        piVar2[2] = iVar6;
        memw();
        iStack_34 = iVar3;
        iVar3 = (*(code *)&SUB_4008b33c)(piVar2,uVar1,0xc);
        if (iVar3 != 0) {
          uStack_24 = 1;
          memw();
        }
        memw();
        (*(code *)&SUB_4008b3d0)(auStack_30,piVar2,0xc);
        (*(code *)&SUB_4008b3d0)(uVar1,piVar2,0xc);
        iVar3 = FUN_401019d4(_DAT_3ffbde84,uVar4,&uStack_38,0x18,0);
        if (iVar3 != 0) {
          uVar1 = (*(code *)&SUB_40094b80)();
          FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"failed\n",uVar1,&PTR_s_STA_DEF_3f40e714,iVar3);
        }
      }
    }
  }
  return;
}

