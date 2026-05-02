// Function : FUN_40131880
// Address  : 0x40131880
// Size     : 124 bytes


undefined4 FUN_40131880(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar3 = iVar2 * 4;
  uVar4 = param_3;
  uVar6 = uVar3;
  if (param_3 <= uVar3) {
    for (; uVar6 = param_3, uVar4 != uVar3; uVar4 = uVar4 + 1) {
      if ((*(uint *)(*(int *)(param_1 + 8) + (uVar4 & 0xfffffffc)) >> ((uVar4 & 3) << 3) & 0xff) !=
          0) {
        return 0xfffffff8;
      }
    }
  }
  uVar4 = 0;
  while (uVar6 != uVar4) {
    uVar5 = uVar4 & 0xfffffffc;
    puVar7 = (undefined1 *)(param_2 + uVar4);
    uVar1 = uVar4 & 3;
    uVar4 = uVar4 + 1;
    *puVar7 = (char)(*(uint *)(*(int *)(param_1 + 8) + uVar5) >> (uVar1 << 3));
    memw();
    memw();
  }
  if (uVar3 < param_3) {
    (*(code *)&SUB_4008b530)(param_2 + uVar3,0,param_3 + iVar2 * -4);
  }
  return 0;
}

