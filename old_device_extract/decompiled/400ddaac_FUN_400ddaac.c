// Function : FUN_400ddaac
// Address  : 0x400ddaac
// Size     : 79 bytes


undefined4 FUN_400ddaac(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = "Stopped";
  if (*param_2 == '\x03') {
    if ((byte)param_2[2] < 0x28) {
      if (*(float *)(param_2 + 8) <= 0.0) {
        uVar2 = (*(code *)&SUB_40002c34)(*(float *)(param_2 + 8),"Stopped");
        FUN_400f06a4(0x3ffc5490,"er: %d\n",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
        return 0;
      }
      return 1;
    }
    pcVar1 = "d: %d)\n";
  }
  FUN_400f06a4(0x3ffc5490,pcVar1);
  return 0;
}

