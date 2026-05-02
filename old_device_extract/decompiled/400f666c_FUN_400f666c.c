// Function : FUN_400f666c
// Address  : 0x400f666c
// Size     : 107 bytes


char FUN_400f666c(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  
  piVar2 = (int *)(param_1 * 4 + 0x3ffc5588);
  iVar1 = *piVar2;
  cVar3 = *(char *)(iVar1 + 0x1c);
  if ((cVar3 == '\0') ||
     (iVar1 = (*(code *)&SUB_4008eb98)
                        (*(undefined4 *)(iVar1 + 0xd8),iVar1 + 0x1d,*(undefined1 *)(iVar1 + 0x9d),1)
     , iVar1 != 1)) {
    cVar3 = '\0';
  }
  else {
    iVar1 = param_1 * 0x10 + 0x3ffbdc7c;
    (*(code *)&SUB_40092a98)(iVar1,0xffffffff);
    iVar4 = *piVar2;
    *(uint *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + (uint)*(byte *)(iVar4 + 0x9d);
    *(undefined1 *)(iVar4 + 0x1c) = 0;
    memw();
    memw();
    (*(code *)&SUB_40092bec)(iVar1);
    FUN_400f65f0(*(undefined4 *)*piVar2);
  }
  return cVar3;
}

