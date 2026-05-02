// Function : FUN_4011d3b0
// Address  : 0x4011d3b0
// Size     : 186 bytes


/* WARNING: Removing unreachable block (ram,0x4011d3d4) */
/* WARNING: Removing unreachable block (ram,0x4011d3d7) */
/* WARNING: Removing unreachable block (ram,0x4011d3de) */
/* WARNING: Removing unreachable block (ram,0x4011d3e5) */
/* WARNING: Removing unreachable block (ram,0x4011d3ec) */
/* WARNING: Removing unreachable block (ram,0x4011d3f7) */

void FUN_4011d3b0(undefined4 *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)*param_1;
  uVar1 = 0xfa;
  uVar3 = puVar4[2];
  if (uVar3 != 0) {
    if ((((char)((int *)param_1[2])[5] == '\0') && (*(int *)param_1[2] == 0x5f66695f)) &&
       ((puVar4[0xd] & 0x20) == 0)) {
      *(undefined1 *)(uVar3 + 0x14) = 0x2e;
      *(undefined1 *)(uVar3 + 0x2c) = 0x2e;
      memw();
      param_1[2] = &DAT_3f40fba4;
    }
    uVar2 = *puVar4 & 0xf0;
    if (uVar2 == 0x20) {
      uVar1 = FUN_40113770(uVar3,param_1[2],*(undefined2 *)(param_1 + 3));
    }
    else if (uVar2 == 0x40) {
      uVar1 = FUN_4010c318(uVar3,param_1[2]);
    }
    else if (uVar2 == 0x10) {
      uVar1 = FUN_4010cb74(uVar3,param_1[2],*(undefined2 *)(param_1 + 3));
    }
    else {
      uVar1 = 0xfa;
    }
  }
  *(undefined1 *)(param_1 + 1) = uVar1;
  memw();
  memw();
  FUN_4011ad9c(param_1[9]);
  return;
}

