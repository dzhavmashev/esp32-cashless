// Function : FUN_400f2e08
// Address  : 0x400f2e08
// Size     : 127 bytes


uint FUN_400f2e08(int *param_1,char param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (param_1 == (int *)0x0) {
LAB_400f2e12:
    uVar1 = 0;
  }
  else {
    puVar3 = &DAT_3ff40000;
    if (((char)param_1[1] != '\0') && (puVar3 = &DAT_3ff50000, (char)param_1[1] != '\x01')) {
      puVar3 = &DAT_3ff6e000;
    }
    while (memw(), (*(uint *)(puVar3 + 0x30) & 0x3ff) < 0x1e) {
      if (param_2 != '\0') goto LAB_400f2e12;
      (*(code *)&SUB_40008534)(1000);
    }
    if (*param_1 != 0) {
      do {
        iVar2 = (*(code *)&SUB_40090010)(*param_1,0xffffffff);
      } while (iVar2 != 1);
    }
    memw();
    memw();
    uVar1 = (*(uint *)(puVar3 + 0x2c) & 0xfffff) + (*(uint *)(puVar3 + 0x28) & 0xfffff) >> 1;
    if (*param_1 != 0) {
      (*(code *)&SUB_4008fab8)(*param_1,0,0);
    }
  }
  return uVar1;
}

