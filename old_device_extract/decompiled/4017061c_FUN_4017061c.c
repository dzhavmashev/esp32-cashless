// Function : FUN_4017061c
// Address  : 0x4017061c
// Size     : 62 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_4017061c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)0x3ffc7ea4;
  if ((DAT_3ffc7ea0 != '\0') &&
     (puVar1 = (undefined4 *)(*(code *)&LAB_400fc833_1)(_DAT_3ffc7e9c), puVar1 == (undefined4 *)0x0)
     ) {
    puVar1 = (undefined4 *)(*(code *)&SUB_40094d60)(8);
    puVar2 = puVar1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40170647;
    do {
      puVar2 = (undefined4 *)FUN_401701ec();
LAB_40170647:
      iVar3 = (*(code *)&LAB_400fc85b_1)(_DAT_3ffc7e9c,puVar2);
    } while (iVar3 != 0);
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  return puVar1;
}

