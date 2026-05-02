// Function : FUN_401214a0
// Address  : 0x401214a0
// Size     : 92 bytes


undefined4 FUN_401214a0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 < &DAT_00000004) goto LAB_401214b8;
  pcVar3 = &DAT_3f419a9c;
  uVar2 = 0x105;
  while( true ) {
    while( true ) {
      (*(code *)&SUB_40094c54)("use/src/esp_efuse_utility.c",uVar2,"13FFC))",pcVar3);
LAB_401214b8:
      iVar1 = (int)param_1 * 8;
      param_1 = (int *)(&DAT_3f419a7c + iVar1);
      if (param_2 <= (undefined4 *)((uint)(*(int *)(&DAT_3f419a80 + iVar1) - *param_1) >> 2)) break;
      pcVar3 = "ility.c";
      uVar2 = 0x106;
    }
    param_2 = (undefined4 *)((int)param_2 * 4 + *param_1);
    param_1 = param_2 + -0xffc0000;
    if ((int *)0x13ffc < param_1) break;
    uVar2 = 0x10b;
    pcVar3 = "eq_size";
  }
  memw();
  return *param_2;
}

