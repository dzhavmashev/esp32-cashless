// Function : FUN_4010afc4
// Address  : 0x4010afc4
// Size     : 55 bytes


void FUN_4010afc4(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar1 = param_1;
  if (param_1 != 0) goto LAB_4010afdd;
  pcVar3 = "e/mem.c";
  uVar2 = 0x102;
  while( true ) {
    uVar1 = (*(code *)&SUB_40094c54)(" memory",uVar2,"N(rmem)",pcVar3);
LAB_4010afdd:
    if (param_1 == (param_1 + 3 & 0xfffffffc)) break;
    pcVar3 = "!= NULL";
    uVar2 = 0x103;
  }
  (*(code *)&SUB_40094d80)(uVar1);
  return;
}

