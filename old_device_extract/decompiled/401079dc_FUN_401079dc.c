// Function : FUN_401079dc
// Address  : 0x401079dc
// Size     : 106 bytes


undefined1 * FUN_401079dc(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  if (0xf < param_1 - 0x30U) {
    return (undefined1 *)0x0;
  }
  iVar3 = (param_1 - 0x30U) * 0x18;
  if (*(int *)(&DAT_3ffc58c8 + iVar3) == 0) {
    return (undefined1 *)0x0;
  }
  FUN_4011acdc(iVar3 + 0x3ffc58dc);
  if (*(char *)(iVar3 + 0x3ffc58d8) == '\0') {
    cVar1 = (&DAT_3ffc58d7)[iVar3];
    (&DAT_3ffc58d7)[iVar3] = cVar1 + '\x01';
    memw();
    bVar2 = true;
    if ((char)(cVar1 + '\x01') != '\0') goto LAB_40107a3a;
    memw();
    (*(code *)&SUB_40094c54)("!= NULL",0x169,"_socket","!= NULL");
  }
  bVar2 = false;
LAB_40107a3a:
  FUN_4011ad00(iVar3 + 0x3ffc58dc);
  if (!bVar2) {
    return (undefined1 *)0x0;
  }
  return &DAT_3ffc58c8 + iVar3;
}

