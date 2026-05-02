// Function : FUN_4017c4f8
// Address  : 0x4017c4f8
// Size     : 164 bytes


undefined4 FUN_4017c4f8(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((param_3 & 3) != 0) {
    param_2 = FUN_4017c1d4(param_1,param_2,
                           *(undefined4 *)
                            (
                            "/builds/idf/crosstool-NG/.build/xtensa-esp32-elf/src/newlib/newlib/libc/stdlib/mprec.c"
                            + ((param_3 & 3) - 1) * 4 + 0x50),0);
  }
  param_3 = (int)param_3 >> 2;
  if (param_3 != 0) {
    if (*(int *)(param_1 + 0x24) == 0) {
      puVar1 = (undefined4 *)(*(code *)&SUB_40094d60)(0x10);
      *(undefined4 **)(param_1 + 0x24) = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)(*(code *)&SUB_40094c54)(&DAT_3f4260d0,0x1ae,0,"ity");
      }
      puVar1[1] = 0;
      puVar1[2] = 0;
      *puVar1 = 0;
      puVar1[3] = 0;
    }
    iVar4 = *(int *)(param_1 + 0x24);
    puVar1 = *(undefined4 **)(iVar4 + 8);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)FUN_4017c3b0(param_1,0x271);
      *(undefined4 **)(iVar4 + 8) = puVar1;
      *puVar1 = 0;
    }
    while( true ) {
      puVar3 = puVar1;
      if ((param_3 & 1) != 0) {
        uVar2 = FUN_4017c3d8(param_1,param_2,puVar3);
        FUN_4017c190(param_1,param_2);
        param_2 = uVar2;
      }
      param_3 = (int)param_3 >> 1;
      if (param_3 == 0) break;
      puVar1 = (undefined4 *)*puVar3;
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)FUN_4017c3d8(param_1,puVar3,puVar3);
        *puVar3 = puVar1;
        *puVar1 = 0;
      }
    }
  }
  return param_2;
}

