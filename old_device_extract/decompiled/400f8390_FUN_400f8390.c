// Function : FUN_400f8390
// Address  : 0x400f8390
// Size     : 273 bytes


undefined4 FUN_400f8390(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + 0xc) == 0) {
    uVar2 = (*(code *)&SUB_40083c60)();
    uVar1 = 0;
    if (1 < param_2) {
      return 0;
    }
    uVar3 = (uint)*(ushort *)(param_1 + 0xf);
    if (uVar2 < uVar3) {
      memw();
      uVar1 = (*(code *)&SUB_40094b80)();
      memw();
      FUN_4012113c(1,"n_count","und %d\n",uVar1,"n_count",uVar3 / 100,uVar3 % 100,uVar2 / 100,
                   uVar2 % 100);
      uVar1 = 0xffffffff;
    }
    if (param_2 != 1) {
      return uVar1;
    }
    uVar3 = (uint)*(ushort *)(param_1 + 0x11);
    if (0xfffd < (uVar3 - 1 & 0xffff)) {
      return uVar1;
    }
    if (uVar2 <= uVar3) {
      return uVar1;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"n_count","v%d.%d\n",uVar1,"n_count",uVar3 / 100,uVar3 % 100,uVar2 / 100,
                 uVar2 % 100);
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"n_count","ot_comm",uVar1,"n_count",0,*(undefined2 *)(param_1 + 0xc));
  }
  return 0xffffffff;
}

