// Function : FUN_40107a48
// Address  : 0x40107a48
// Size     : 121 bytes


int * FUN_40107a48(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (0xf < param_1 - 0x30U) {
    return (int *)0x0;
  }
  iVar2 = (param_1 - 0x30U) * 0x18;
  if (*(int *)(&DAT_3ffc58c8 + iVar2) == 0) {
    return (int *)0x0;
  }
  iVar3 = iVar2 + 0x3ffc58dc;
  FUN_4011acdc(iVar3);
  if (*(char *)(iVar2 + 0x3ffc58d8) == '\0') {
    cVar1 = (&DAT_3ffc58d7)[iVar2];
    (&DAT_3ffc58d7)[iVar2] = cVar1 + '\x01';
    memw();
    if ((char)(cVar1 + '\x01') != '\0') {
      FUN_4011ad00(iVar3);
      return (int *)(&DAT_3ffc58c8 + iVar2);
    }
    uVar4 = 0x185;
    memw();
  }
  else {
    if ((&DAT_3ffc58d7)[iVar2] != '\0') goto LAB_40107a8c;
    uVar4 = 0x17d;
  }
  (*(code *)&SUB_40094c54)("!= NULL",uVar4,"lect_cb","!= NULL");
LAB_40107a8c:
  FUN_4011ad00(iVar3);
  return (int *)0x0;
}

