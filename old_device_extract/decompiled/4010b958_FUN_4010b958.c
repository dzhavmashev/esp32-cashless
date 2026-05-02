// Function : FUN_4010b958
// Address  : 0x4010b958
// Size     : 57 bytes


undefined4 * FUN_4010b958(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  if (param_1 == (char *)0x0) {
LAB_4010b95d:
    puVar2 = (undefined4 *)0x0;
  }
  else {
    cVar1 = (*(code *)&SUB_4008a3f0)(param_1 + 2);
    puVar2 = (undefined4 *)&DAT_3ffc83fc;
    do {
      puVar2 = (undefined4 *)*puVar2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_4010b95d;
    } while (((*(char *)((int)puVar2 + 0xee) != cVar1) || (*param_1 != *(char *)(puVar2 + 0x3b))) ||
            (param_1[1] != *(char *)((int)puVar2 + 0xed)));
  }
  return puVar2;
}

