// Function : FUN_4010caa8
// Address  : 0x4010caa8
// Size     : 74 bytes


void FUN_4010caa8(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (param_1 != 0) goto LAB_4010cac0;
  pcVar4 = "e/tcp.c";
  uVar3 = 0x13f;
  while( true ) {
    (*(code *)&SUB_40094c54)(" LISTEN",uVar3,"hutdown",pcVar4);
LAB_4010cac0:
    uVar1 = *(ushort *)(param_1 + 0x46);
    if (((uVar1 & 0x200) == 0) || (iVar2 = *(int *)(param_1 + 0xa8), iVar2 == 0)) goto LAB_4010caed;
    if (*(char *)(iVar2 + 0x49) != '\0') break;
    pcVar4 = "!= NULL";
    uVar3 = 0x143;
  }
  *(char *)(iVar2 + 0x49) = *(char *)(iVar2 + 0x49) + -1;
  *(ushort *)(param_1 + 0x46) = uVar1 & 0xfdff;
  memw();
LAB_4010caed:
  memw();
  return;
}

