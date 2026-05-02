// Function : FUN_401717d8
// Address  : 0x401717d8
// Size     : 177 bytes


void FUN_401717d8(int param_1,int *param_2,int *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint local_40 [4];
  uint uStack_30;
  undefined4 uStack_2c;
  
  uVar4 = *(uint *)(param_1 + 0x10) >> 3 & 0xff;
  uVar2 = FUN_401713c4(uVar4,param_1);
  iVar6 = 0;
  for (; *param_3 != 0; param_3 = (int *)((int)param_3 + *param_3 + 4)) {
    if (param_3[1] != 0) {
      if (((*(uint *)(param_1 + 0x10) & 4) != 0) &&
         (iVar5 = (int)param_3 + (4 - param_3[1]), bVar1 = iVar6 != iVar5, iVar6 = iVar5, bVar1)) {
        uVar4 = FUN_40171528(iVar5);
        uVar2 = FUN_401713c4(uVar4 & 0xff,param_1);
      }
      if (uVar4 == 0) {
        local_40[0] = param_3[2];
        uVar3 = local_40[0];
      }
      else {
        uStack_30 = uVar4 & 0xff;
        uStack_2c = uVar2;
        FUN_40171410(uStack_30,uVar2,param_3 + 2,local_40);
        uVar3 = FUN_4017138c(uStack_30);
        uVar7 = 0xffffffff;
        if (uVar3 < 4) {
          uVar7 = (1 << 0x20 - ((uVar3 & 3) * -8 + 0x20)) - 1;
        }
        uVar2 = uStack_2c;
        uVar3 = uVar7 & local_40[0];
      }
      if ((uVar3 != 0) && (iVar5 = *param_2, iVar5 != 0)) {
        iVar8 = *(int *)(iVar5 + 4);
        *(int *)(iVar5 + 4) = iVar8 + 1;
        *(int **)(iVar5 + iVar8 * 4 + 8) = param_3;
      }
    }
  }
  return;
}

