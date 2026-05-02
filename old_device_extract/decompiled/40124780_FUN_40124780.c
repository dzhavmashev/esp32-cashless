// Function : FUN_40124780
// Address  : 0x40124780
// Size     : 94 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40124780(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0x1e0);
  if (puVar2 != (undefined4 *)0x0) {
    (*(code *)&SUB_4008b3d0)(puVar2 + 2,param_2,6);
    *puVar2 = param_1;
    uVar1 = _DAT_3ffc765c;
    puVar2[1] = *param_1;
    if ((uVar1 & 1) == 0) {
      _DAT_3ffc765c = uVar1 | 1;
      puRam3ffc7660 = puVar2;
      puVar2[0x71] = 0;
      memw();
    }
  }
  memw();
  return;
}

