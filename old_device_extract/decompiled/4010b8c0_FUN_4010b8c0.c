// Function : FUN_4010b8c0
// Address  : 0x4010b8c0
// Size     : 116 bytes


uint FUN_4010b8c0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  iVar1 = param_1;
  if (param_1 != 0) goto LAB_4010b8d9;
  pcVar5 = "d addr6";
  uVar4 = 0x5d9;
  while( true ) {
    iVar1 = (*(code *)&SUB_40094c54)("d netif",uVar4,"ip6addr",pcVar5);
LAB_4010b8d9:
    if (param_2 != (int *)0x0) break;
    pcVar5 = "d netif";
    uVar4 = 0x5da;
  }
  if (((char)param_2[4] == '\0') || ((char)param_2[4] == (char)(*(char *)(param_1 + 0xee) + '\x01'))
     ) {
    piVar2 = (int *)(iVar1 + 0x4c);
    uVar3 = 0;
    do {
      if ((((*(char *)(iVar1 + uVar3 + 0x94) != '\0') && (*piVar2 == *param_2)) &&
          (piVar2[1] == param_2[1])) && ((piVar2[2] == param_2[2] && (piVar2[3] == param_2[3])))) {
        return uVar3 & 0xff;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 6;
    } while (uVar3 != 3);
  }
  return 0xff;
}

