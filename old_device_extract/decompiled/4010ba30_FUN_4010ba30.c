// Function : FUN_4010ba30
// Address  : 0x4010ba30
// Size     : 75 bytes


undefined4 * FUN_4010ba30(undefined4 param_1,undefined2 param_2,uint param_3)

{
  undefined4 *puVar1;
  
  if ((param_3 & 0xffffffbf) != 1) {
    (*(code *)&SUB_40094c54)("if_init",0x14e,"realloc","/pbuf.c");
  }
  puVar1 = (undefined4 *)FUN_4010b058(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = param_1;
    *(undefined2 *)(puVar1 + 2) = param_2;
    *(undefined2 *)((int)puVar1 + 10) = param_2;
    *(char *)(puVar1 + 3) = (char)param_3;
    *(undefined1 *)((int)puVar1 + 0xd) = 0;
    *(short *)((int)puVar1 + 0xe) = (short)(param_3 & 0xffffffbf);
    memw();
    puVar1[4] = 0;
    puVar1[5] = 0;
  }
  memw();
  return puVar1;
}

