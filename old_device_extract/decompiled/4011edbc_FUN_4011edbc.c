// Function : FUN_4011edbc
// Address  : 0x4011edbc
// Size     : 150 bytes


undefined4 FUN_4011edbc(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  undefined1 auStack_26 [38];
  
  if (param_1 == 0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "0x%02x\n";
  }
  else {
    if (param_2 < 4) {
      iVar2 = FUN_4011ecc8(auStack_26);
      if (iVar2 != 0) {
        FUN_4011ecfc(auStack_26);
        FUN_4011ec78(auStack_26);
      }
      if (param_2 == 2) {
        (*(code *)&SUB_4008b3d0)(param_1,auStack_26,6);
        cVar3 = *(char *)(param_1 + 5) + '\x02';
      }
      else if (param_2 == 3) {
        (*(code *)&SUB_4008b3d0)();
        cVar3 = *(char *)(param_1 + 5) + '\x03';
      }
      else {
        if (param_2 != 1) {
          (*(code *)&SUB_4008b3d0)();
          return 0;
        }
        (*(code *)&SUB_4008b3d0)();
        cVar3 = *(char *)(param_1 + 5) + '\x01';
      }
      *(char *)(param_1 + 5) = cVar3;
      memw();
      memw();
      return 0;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "s NULL\n";
  }
  FUN_4012113c(1,"_source",pcVar4,uVar1,"_source");
  return 0x102;
}

