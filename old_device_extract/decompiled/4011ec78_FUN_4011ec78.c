// Function : FUN_4011ec78
// Address  : 0x4011ec78
// Size     : 79 bytes


uint FUN_4011ec78(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if (param_1 == (byte *)0x0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar3 = "tem_api";
  }
  else {
    bVar1 = *param_1;
    if ((bVar1 & 1) == 0) {
      (*(code *)&SUB_4008b3d0)(&DAT_3ffc66e4,param_1,6);
      return bVar1 & 1;
    }
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar3 = "s NULL\n";
  }
  FUN_4012113c(1,"_source",pcVar3,uVar2,"_source");
  return 0x102;
}

