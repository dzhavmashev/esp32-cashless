// Function : FUN_40152170
// Address  : 0x40152170
// Size     : 56 bytes


void FUN_40152170(int param_1,uint param_2)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  
  if ((param_1 != 0) && (param_2 < 6)) {
    puVar1 = &DAT_3ffc87f0 + param_2 * 8;
    cVar2 = '\x02';
    do {
      iVar3 = *(int *)(puVar1 + 0xa0);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
        (*(code *)&SUB_4008b3d0)(param_1,*(int *)(iVar3 + 4),*(undefined1 *)(iVar3 + 8));
        param_1 = param_1 + (uint)*(byte *)(*(int *)(puVar1 + 0xa0) + 8);
      }
      cVar2 = cVar2 + -1;
      puVar1 = puVar1 + 4;
    } while (cVar2 != '\0');
  }
  return;
}

