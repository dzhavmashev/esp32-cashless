// Function : FUN_400f2130
// Address  : 0x400f2130
// Size     : 122 bytes


void FUN_400f2130(int *param_1,char param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      do {
        iVar1 = func_0x40090018(*param_1,0xffffffff);
      } while (iVar1 != 1);
    }
    do {
      puVar2 = &DAT_3ff40000;
      if (((char)param_1[1] != '\0') && (puVar2 = &DAT_3ff50000, (char)param_1[1] != '\x01')) {
        puVar2 = &DAT_3ff6e000;
      }
      memw();
      memw();
      memw();
    } while (((*(uint *)(puVar2 + 0x1c) >> 0x10 & 0xff) != 0) ||
            (memw(), (*(uint *)(puVar2 + 0x1c) >> 0x18 & 0xf) != 0));
    if ((param_2 == '\0') && (iVar1 = FUN_400f77c8(), iVar1 != 0)) {
      func_0x4008f004(iVar1,"t_intr)",0x2c1,&DAT_3f40aea4,"-uart.c");
    }
    if (*param_1 != 0) {
      func_0x4008fac0(*param_1,0,0);
    }
  }
  return;
}

