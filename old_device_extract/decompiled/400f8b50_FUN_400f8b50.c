// Function : FUN_400f8b50
// Address  : 0x400f8b50
// Size     : 46 bytes


void FUN_400f8b50(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  uVar4 = CONCAT44(param_2,param_1);
  if (param_1 != 0) goto LAB_400f8b6c;
  pcVar3 = "ed hash";
  uVar2 = 0x1e;
  while( true ) {
    uVar4 = (*(code *)&SUB_40094c54)("src/idf/bootloader_sha.c",uVar2,"_finish",pcVar3);
LAB_400f8b6c:
    iVar1 = FUN_4013f87c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    if (iVar1 == 0) break;
    pcVar3 = "r_sha.c";
    uVar2 = 0x21;
  }
  return;
}

