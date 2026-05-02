// Function : FUN_400f8b80
// Address  : 0x400f8b80
// Size     : 65 bytes


void FUN_400f8b80(int param_1,int param_2)

{
  int iVar1;
  int extraout_a3;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = param_2;
  if (param_1 != 0) goto LAB_400f8b9b;
  pcVar3 = "ed hash";
  uVar2 = 0x27;
  while( true ) {
    (*(code *)&SUB_40094c54)("src/idf/bootloader_sha.c",uVar2,"et == 0",pcVar3);
    iVar1 = extraout_a3;
LAB_400f8b9b:
    if ((param_2 == 0) || (iVar1 = FUN_4013f8a4(param_1,iVar1), iVar1 == 0)) break;
    pcVar3 = "r_sha.c";
    uVar2 = 0x2b;
  }
  FUN_4013f798(param_1);
  (*(code *)&SUB_40094d80)(param_1);
  return;
}

